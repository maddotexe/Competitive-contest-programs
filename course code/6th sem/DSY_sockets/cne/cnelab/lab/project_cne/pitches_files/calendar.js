Date.prototype.previousDay = function() {
	var day = new Date(this.getFullYear(), this.getMonth(), this.getDate());
	// Guaranteed to go into the prev day even with weird date/time adjustments.
	var next = new Date(day.getTime() - 18 * 60 * 60 * 1000);
	return new Date(next.getFullYear(), next.getMonth(), next.getDate());	
}
Date.prototype.nextDay = function() {
	var day = new Date(this.getFullYear(), this.getMonth(), this.getDate());
	// Guaranteed to go into the next day even with weird date/time adjustments.
	var next = new Date(day.getTime() + 36 * 60 * 60 * 1000);
	return new Date(next.getFullYear(), next.getMonth(), next.getDate());
}

function processSchedule(json) {
	var startDate = new Date(json['start']);	
	var weekDays = {};
	for (var i = 0; json['days'][i]; i++) {
		weekDays[json['days'][i][0]] = i;
	}
	var slots = {};
	for (var i = 0; json['slots'][i]; i++) {
		var slot = json['slots'][i];
		var slotLetter = slot[0];
		var slotDays = {};
		if (typeof(slot[slot.length - 1]) == 'object') {
			slotDays = slot.pop();
		}
		for (var j = 1; slot[j]; j++) {
			var weekDay = slot[j];
			slotDays[weekDays[weekDay]] = true;
		}
		slots[slotLetter] = slotDays;
	}
	
	var schedule = [];
	
	// Build out days until startDate.
	var weekSchedule = [];
	var date = new Date(json['start']);
	while (date.getDay() != 0) {
		date = date.previousDay();
		weekSchedule.push([date]);
	}
	weekSchedule = weekSchedule.reverse();
	date = startDate;

	// Process schedule elements.
	var daySchedule = [date];
	for (var i = 0; json['schedule'][i]; i++) {
		var item = json['schedule'][i];
		var forceAdvance = false;
		
		// Process force-day flag.
		var splitSlot = item[0].split(':');
		var slotType = splitSlot[0];
		if (slotType.substr(slotType.length - 1, 1) == '*') {
			slotType = slotType.substr(0, slotType.length - 1);
			forceAdvance = true;
		}
		item[0] = slotType;
		var forceDay = splitSlot[1] ? weekDays[splitSlot[1]] : false;
		var slotDays = slots[slotType];
	
		// Don't allow two slots of the same type in a day.
		if (!slots[slotType]['shared'] && daySchedule.length > 1) {
			forceAdvance = true;
		} else if (!forceAdvance) {
			for (var j = 1; daySchedule[j]; j++) {
				var otherSlot = daySchedule[j][0];
				if (slotType == otherSlot || !slots[otherSlot]['shared']) {
					forceAdvance = true;
					break;
				}
			}
		}
		
		// Advance to a day containing a desired slot.
		while (true) {
			var forceDayOk = !forceDay || (forceDay && date.getDay() == forceDay);
			var slotOk = forceDay || slotDays[date.getDay()];
			if (forceDayOk && !forceAdvance && slotOk) {
				break;
			}
			weekSchedule.push(daySchedule);
			date = date.nextDay();
			daySchedule = [date];
			if (date.getDay() == 0) {				
				schedule.push(weekSchedule);
				weekSchedule = [];
			}
			forceAdvance = false;
		}
		
		daySchedule.push(item);
	}

	// Close out the week.
	do {
		weekSchedule.push(daySchedule);
		date = date.nextDay();
		daySchedule = [date];
	} while (date.getDay() != 0);
	schedule.push(weekSchedule);

	return schedule;
}

function renderSchedule(div, json, schedule) {
	// Build the table heading.
	var table = $(document.createElement('table'));
	var header = $(document.createElement('tr'));
	var weekDays = json['days'];
	for (var i = 0; weekDays[i]; i++) {
		if (weekDays[i][2] && weekDays[i][2]['invisible']) {
			continue;
		}
		var heading = $(document.createElement('th'));
		heading.addClass('day-' + weekDays[i][0]);
		heading.html(weekDays[i][1]);
		header.append(heading);
	}
	table.append(header);
	
	// Build out each week.
	for (var i = 0; schedule[i]; i++) {
		var weekRow = $(document.createElement('tr'));
		for (var j = 0; j < weekDays.length; j++) {
			if (weekDays[j][2] && weekDays[j][2]['invisible']) {
				continue;
			}
			var dayCell = $(document.createElement('td'));
			dayCell.addClass('day-' + weekDays[j][0]);
			if (schedule[i][j].length == 1) {
				dayCell.addClass('day-empty');
			}
			
			var dayDate = $(document.createElement('div'));
			dayDate.addClass('schedule-date');
			var date = schedule[i][j][0];
			dayDate.html(date.getDate().toString() + ' ' +
					     json['months'][date.getMonth()]);
			dayCell.append(dayDate);
			
			for (var k = 1; schedule[i][j][k]; k++) {
				var itemDiv = $(document.createElement('div'));
				itemDiv.addClass('schedule-item');
				itemDiv.addClass('schedule-' + schedule[i][j][k][0]);
				dayCell.addClass('schedule-' + schedule[i][j][k][0]);
				itemDiv.html(schedule[i][j][k][1]);
				dayCell.append(itemDiv);
			}
			
			weekRow.append(dayCell);
		}
		table.append(weekRow);
	}
	
	// Insert the table into the document.
	div.html('');
	div.append(table);
}

function doSchedule(divName) {
	var calendarDiv = $(divName);
	var jsonUrl = $('a', calendarDiv).first().attr('href');
	$.getJSON(jsonUrl, function(data, textstatus) {
		var schedule = processSchedule(data);
		renderSchedule(calendarDiv, data, schedule);
	});
}

var currently_visible = null;   
var currently_visible2 = null;   
var currently_visible3 = null;   
var currently_visible4 = null;   

function calcHeight()
{
  //find the height of the internal page
  var the_height=
    document.getElementById('pubsiframe').contentWindow.
      document.body.scrollHeight;

  //change the height of the iframe
  document.getElementById('pubsiframe').height=
      the_height;
}

function resizeparent() {
    var h = document.body.scrollHeight; 
    parent.window.location.hash = h;  
}

function submitform() {
  
    if(document.getElementById('peoplebox').checked) {
      document.getElementById('people_id').name = 'people_id';
    }
    
    if(document.getElementById('typebox').checked) {
      document.getElementById('type_id').name = 'type_id';
    }
    
    if(document.getElementById('titlebox').checked) {
      document.getElementById('title').name = 'title';
    }
      
    x = document.getElementById('filterform')
      
    x.submit();
}   

function submitargs() {
    var args = "?fragment=yes&";
    
    if(document.getElementById('peoplebox').checked) {
      args += "people_id=" + document.getElementById('people_id').value + '&';
    }
    
    if(document.getElementById('typebox').checked) {
      args += "type_id=" + document.getElementById('type_id').value + '&';
    }
    
    if(document.getElementById('titlebox').checked) {
      args += "title=" + document.getElementById('title').value + '&';
    }
    
    return args;
}   



function hideall() {
  document.getElementById('booktitle').style.display = 'none';   
  document.getElementById('publisher').style.display = 'none';   
  document.getElementById('journal').style.display = 'none';   
  document.getElementById('institution').style.display = 'none';   
  document.getElementById('series').style.display = 'none';   
  document.getElementById('address').style.display = 'none';   
  document.getElementById('edition').style.display = 'none';   
  document.getElementById('volume').style.display = 'none';   
  document.getElementById('number').style.display = 'none';   
  document.getElementById('pages').style.display = 'none';   
  document.getElementById('venue').style.display = 'none';   
  document.getElementById('month').style.display = 'none';   
  document.getElementById('year').style.display = 'none';   
  document.getElementById('editor').style.display = 'none';   

    
}
 
function showall() {
  document.getElementById('booktitle').style.display = '';   
  document.getElementById('publisher').style.display = '';   
  document.getElementById('journal').style.display = '';   
  document.getElementById('institution').style.display = '';   
  document.getElementById('series').style.display = '';   
  document.getElementById('address').style.display = '';   
  document.getElementById('edition').style.display = '';   
  document.getElementById('volume').style.display = '';   
  document.getElementById('number').style.display = '';   
  document.getElementById('pages').style.display = '';   
  document.getElementById('venue').style.display = '';   
  document.getElementById('month').style.display = '';   
  document.getElementById('year').style.display = '';   
}

function showbook() {
  document.getElementById('publisher').style.display = '';   
  document.getElementById('series').style.display = '';   
  document.getElementById('edition').style.display = '';   
  document.getElementById('pages').style.display = '';   
  document.getElementById('month').style.display = '';   
  document.getElementById('year').style.display = '';   
}
  
function showbookchapter() {
  document.getElementById('booktitle').style.display = '';   
  document.getElementById('editor').style.display = '';   
  document.getElementById('publisher').style.display = '';   
  document.getElementById('series').style.display = '';   
  document.getElementById('edition').style.display = '';   
  document.getElementById('pages').style.display = '';   
  document.getElementById('month').style.display = '';   
  document.getElementById('year').style.display = '';   
}


function showconference() {
  document.getElementById('booktitle').style.display = '';   
  document.getElementById('address').style.display = '';   
  document.getElementById('pages').style.display = '';   
  document.getElementById('month').style.display = '';   
  document.getElementById('year').style.display = '';   
}

function showjournal() {
  document.getElementById('publisher').style.display = '';   
  document.getElementById('journal').style.display = '';   
  document.getElementById('volume').style.display = '';   
  document.getElementById('number').style.display = '';   
  document.getElementById('pages').style.display = '';   
  document.getElementById('month').style.display = '';   
  document.getElementById('year').style.display = '';   
}

function showtalk() {
  document.getElementById('address').style.display = '';   
  document.getElementById('venue').style.display = '';   
  document.getElementById('month').style.display = '';   
  document.getElementById('year').style.display = '';   
}

function showtechnical() {
  document.getElementById('institution').style.display = '';   
  document.getElementById('address').style.display = '';   
  document.getElementById('number').style.display = '';   
  document.getElementById('pages').style.display = '';   
  document.getElementById('month').style.display = '';   
  document.getElementById('year').style.display = '';   
}

function showthesis() {
  document.getElementById('booktitle').style.display = '';   
  document.getElementById('institution').style.display = '';   
  document.getElementById('address').style.display = '';   
  document.getElementById('pages').style.display = '';   
  document.getElementById('month').style.display = '';   
  document.getElementById('year').style.display = '';   
}
   
function showpublicationtypefields() {
    hideall();
    field = document.getElementById('publication_type_id');
    value = field.value;
    if (value == 11 || value == 15) // book or collection
        showbook();
    else if (value == 18) // book chapter
        showbookchapter();
    else if (value == 8 || value == 12 || value == 13) // conference, workshop or poster
        showconference();
    else if (value == 9 || value == 17) // journal or magazine
        showjournal();
    else if (value == 14) // talk
        showtalk();
    else if (value == 10) // technical report
        showtechnical();
    else 
        showthesis();
}


function show(x) {

    if (currently_visible) {
        currently_visible.style.display = 'none';
    }
    card = document.getElementById(x);
    //card.style.visibility='visible';
    card.style.display='';
    
    
    currently_visible = card;
    
}

function show2(x) {

    if (currently_visible2) {
        currently_visible2.style.display = 'none';
    }
    card = document.getElementById(x);
    //card.style.visibility='visible';
    card.style.display='';
    
    
    currently_visible2 = card;
    
}


function show3(x) {

    if (currently_visible3) {
        currently_visible3.style.display = 'none';
    }
    card = document.getElementById(x);
    //card.style.visibility='visible';
    card.style.display='';
    
    
    currently_visible3 = card;
    
}

function show4(x) {

    if (currently_visible4) {
        currently_visible4.style.display = 'none';
    }
    card = document.getElementById(x);
    //card.style.visibility='visible';
    card.style.display='';
    
    
    currently_visible4 = card;
    
}


function resize() {
    f=document.getElementById('relatedfiles'); 
    d=window.frames[0].document.getElementById('relatedfilesbody'); 
    f.height = d.clientHeight;
}

function resize2() {
    f=document.getElementById('relatedlinks'); 
    d=window.frames[1].document.getElementById('relatedlinksbody'); 
    f.height = d.clientHeight;
}

function loadpublications() {
new Ajax.Updater('main2', 'http://sysweb.cs.toronto.edu/publications/list_by_author?people_id=1&fragment=1', { method: 'get' });
}

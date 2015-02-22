class Complex_Number
{
   //  simple class to represent and perform calculations on complex
   //  numbers in the form (a + bi)
	double a, b;


public:

   // Constructors for easy declarations of complex numbers
   Complex_Number ()
   {
   	a = 0;
      b = 0;
   }

   Complex_Number (double a_temp, double b_temp)
   {
   	a = a_temp;
      b = b_temp;
   }

	// Function to copy the a and b values into the parameters
   void Get_ab( double &a_temp, double &b_temp)
   {
   	a_temp = a;
      b_temp = b;
   }

   // Function to set the a and b values of the complex
   // number in the form (a + bi)
   void Set_ab( double a_temp, double b_temp)
   {
   	a = a_temp;
      b = b_temp;
   }

   // Function that adds two complex numbers
   // the result is a modified object of the class (this)
   void Add(Complex_Number comp_num)
   {
   	this->a = comp_num.a + this->a;
      this->b = comp_num.b + this->b;
   }

   // Function that subtracts two complex numbers
   // the result is a modified object of the class (this)
   void Subtract(Complex_Number comp_num)
   {
   	this->a = comp_num.a - this->a;
      this->b = comp_num.b - this->b;
   }

	// Function that multiplies two complex numbers
   // the result is a modified object of the class (this)

   void Multiply(Complex_Number comp_num)
   {
   	double temp_a;
      double temp_b;
      temp_a = this->a * comp_num.a;
      temp_a += (this->b * comp_num.b)*(-1);

      temp_b = this->a * comp_num.b;
      temp_b += this->b * comp_num.a;

      this->a = temp_a;
      this->b = temp_b;
   }



};

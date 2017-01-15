/*Light Mouse
  Luc Volders

Decides on which way the mouse will go by checking
which LDR's get light on and which do not

using 4 LDR's put in a square form
top:    A1, A3
bottom: A0, A2
*/


int s1, s2, s3, s4, x ,y, axy;


void setup()
{
  Mouse.begin();
}

void loop() {
  
  s1 = analogRead(A0);
  s2 = analogRead(A1);
  s3 = analogRead(A2);
  s4 = analogRead(A3);

  x=((s3+s4) -(s1+s2));
  y=((s1+s3)-(s4+s2));
  axy = (abs(abs(x)-abs(y)));
  
  if ((abs(x)>25) && (abs(y)>25)) // test for action
  {
  if ((x<0) && ((abs(x))>(abs(y))) && (y>0) && (axy>100))
    {
      //going left
      Mouse.move(-10, 0, 0);
    }
  if (((x>0) && (y>0)) && (axy>100))
    {
      //going right
      Mouse.move(10, 0, 0);
    }
  if (x<0 && y<0 && axy>100)
    {
      //going up
      Mouse.move(0, -10, 0);
    }
  if (x<0 && (abs(x)<abs(y))&& y>0 && axy>100)
    {  
      //going down
       Mouse.move(0, 10, 0);
    }
  // -------------------------------------------------------
  // schuin
  // -------------------------------------------------------
    if (((x<0) && (y<0)) && (axy<100))
    {
     // moving left-up
      Mouse.move(-10, -10, 0);
    }
    if (((x>0) && (y<0)) && (axy<100))
    {
      //moving right-up
      Mouse.move(10, -10, 0);
    }
    if (((x<0) && (y>0)) && (axy<100))
    {
      //moving left-down
      Mouse.move(-10, 10, 0);
    }
    if (((x>0) && (y>0)) && (axy<100))
    {
      //moving right-down
      Mouse.move(10, 10, 0);
    }
  }
  
  delay(50);
}



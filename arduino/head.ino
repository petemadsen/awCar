#include <Servo.h>

Servo m_head;
int m_head_pos = 0; // -x = left, 0 = center, +x = right
const int m_head_max = 20;


void head_init()
{
  m_head.attach(10);
  m_head.write(90); // center
}


void head_front()
{
  head_to(0);
}


void head_left()
{
  head_to(+m_head_max);
}


void head_right()
{
  head_to(-m_head_max);
}


void head_to(int pos)
{
  Serial.print("head-to ");
  Serial.print(pos);
  Serial.print(" at now ");
  Serial.print(m_head_pos);
  Serial.println();
  
  if (pos == m_head_pos)
    return;

  int dir = pos < m_head_pos ? -1 : +1;

  for (int i=0; i<m_head_max; ++i)
  {
    m_head_pos += dir;
    m_head.write(m_head_pos + 90);
    
    Serial.print("##");
    Serial.print(m_head_pos);
    Serial.print(" / ");
    Serial.println(m_head_pos + 90);
    delay(25);
  }
#if 0    
  Serial.println("to-the-left");
  if (m_head_pos >= m_head_max_left)
    return;
  
  for (int pos = 0; pos <= m_head_max_left; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    m_head.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
#endif
}

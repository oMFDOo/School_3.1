import processing.serial.*;

import cc.arduino.*;


void setup() {  // this is run once.   
  size(640, 360, P3D);
  noStroke();
} 


void draw() {
  background(51);
  pushMatrix();
  translate(300, 180, 0);
  fill(255, 255, 0);
  box(50, 50, 250);
  popMatrix();
  
  pushMatrix();
  translate(285, 180, -50);
  fill(255, 0, 0);
  box(245, 50, 50);
  popMatrix();
  
  pushMatrix();
  translate(270, 180, -175);
  fill(0, 255, 0);
  box(50, 150, 30);
  popMatrix();
  
  pushMatrix();
  translate(270, 180, -175);
  fill(0, 255, 0);
  box(150, 50, 30);
  popMatrix();
}

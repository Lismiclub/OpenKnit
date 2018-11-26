void setDirectionForward() {
  digitalWrite(reset, LOW);
  delay(100);
  digitalWrite(reset, HIGH);
  digitalWrite(dir, LOW);
}

void setDirectionBackward() {
  digitalWrite(reset, LOW);
  delay(100);
  digitalWrite(reset, HIGH);
  digitalWrite(dir, HIGH);
}

void moveOneStep() {
    digitalWrite(steps, HIGH);
    delayMicroseconds(speedRotation);
    digitalWrite(steps, LOW);
    delayMicroseconds(speedRotation);
}

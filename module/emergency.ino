void EMERGENCY() {
    attachInterrupt(digitalPinToInterrupt(thirdBtn), STOP, CHANGE);
}

void STOP() {
    motor_value = 0;
    motor_state = 0;
    buzzer_state = 0;
    redLed_state = 0;
    blueLed_state = 0;
    firstBtn_state = 0;
    secondBtn_state = 0;
    thirdBtn_state = 0;
    WORKING_BUZZER();
    Serial.println("EMERGENCY!");
}

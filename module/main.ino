void INPUT_BTN() {
    unsigned long previous_Millis = 0;
    unsigned long current_Millis = millis();

    firstBtn_state = analogRead(firstBtn);
    secondBtn_state = analogRead(secondBtn);
    thirdBtn_state = analogRead(thirdBtn);

    if(firstBtn_state == 1 || secondBtn_state == 1) {
        previous_Millis = current_Millis;
    }

    if(firstBtn_state == 1 && secondBtn ==1 && current_Millis - previous_Millis <= 40) {
        WORKING_LED();
        WORKING_MOTOR();
        Serial.println("It's working!");
    }

    if(firstBtn_state == 0 || secondBtn_state == 0) {
        NOT_WORKING_LED();
        Serial.println("Not working");
    }
}
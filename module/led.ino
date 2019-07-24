void WORKING_LED() {
    unsigned long previous_Millis = 0;
    unsigned long current_Millis = millis();

    if (current_Millis - previous_Millis >= 500) {
        previous_Millis = current_Millis;
        if (redLed_state == 0) {
            redLed_state = 1;
        } else {
            redLed_state = 0;
        }
        digitalWrite(redLed, redLed_state);
    }
}

void NOT_WORKING_LED() {
    unsigned long previous_Millis = 0;
    unsigned long current_Millis = millis();

    if (current_Millis - previous_Millis >= 500) {
        previous_Millis = current_Millis;
        if (blueLed_state == 0) {
            blueLed_state = 1;
        } else {
            blueLed_state = 0;
        }
        digitalWrite(blueLed, blueLed_state);
    }
}

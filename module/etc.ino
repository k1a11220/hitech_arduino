void WORKING_MOTOR() {
    motor_value += 30;
    if(motor_value == 180) {
        motor_value = 0;
    }
}

void WORKING_BUZZER() {
    buzzer_state = 1;
}
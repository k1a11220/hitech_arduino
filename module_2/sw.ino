void btnPush() {
    static unsigned char oldBtn = 0, newBtn = 0;
    static unsigned char ledState = 0;
    
    Serial.println(newBtn);
    newBtn = digitalRead(8);
    if(oldBtn != newBtn) {
        oldBtn = newBtn;
        if(newBtn == 0) {
            WORKING_LED();
        }
    }
}

package com.heranca;

public class SmartSpeaker extends SmartDevice {
    public static final int MAX = 20; //volume máximo

    private int volume;
    private String channel;


    /**
     * Constructor for objects of class SmartSpeaker
     */
    public SmartSpeaker() {
        // initialise instance variables
        this.volume = 0;
        this.channel = "";
    }

    public SmartSpeaker(String s) {
        // initialise instance variables
        super(s);
        this.channel = "";
        this.volume = 0;
    }

    public SmartSpeaker(String s, String s1, int i) {
        // initialise instance variables
        super(s);
        this.channel = s1;
        this.volume = i >= 0 && i <= MAX ? i : 0;
    }

    public void volumeUp() {
        if (this.volume<MAX) this.volume++;
    }

    public void volumeDown() {
        if (this.volume>0) this.volume--;
    }

    public int getVolume() {
        return this.volume;
    }

    public String getChannel() {
        return this.channel;
    }

    public void setChannel(String c) {
        this.channel = c;
    }

}

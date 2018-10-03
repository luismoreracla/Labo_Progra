package com.example.luis.simonsays;

import android.content.Intent;
import android.media.MediaPlayer;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class Play_Game extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_play__game);

        Button b1=(Button)findViewById(R.id.blue);
        Button b2=(Button)findViewById(R.id.purple);
        Button b3=(Button)findViewById(R.id.gray);
        Button b4=(Button)findViewById(R.id.yellow);
        Button b5=(Button)findViewById(R.id.red);
        Button b6=(Button)findViewById(R.id.green);

        final MediaPlayer mp = MediaPlayer.create(getBaseContext(), R.raw.guitarra);
        final MediaPlayer mpurple = MediaPlayer.create(getBaseContext(), R.raw.purple);
        final MediaPlayer mgray = MediaPlayer.create(getBaseContext(), R.raw.gray);
        final MediaPlayer myellow = MediaPlayer.create(getBaseContext(), R.raw.yellow);
        final MediaPlayer mred = MediaPlayer.create(getBaseContext(), R.raw.red);
        final MediaPlayer mgreen = MediaPlayer.create(getBaseContext(), R.raw.green);

        b1.setOnClickListener(new View.OnClickListener() {

            public void onClick(View v) {
                mp.start();
            }
        });
        b2.setOnClickListener(new View.OnClickListener() {

            public void onClick(View v) {
                mpurple.start();
            }
        });
        b3.setOnClickListener(new View.OnClickListener() {

            public void onClick(View v) {
                mgray.start();
            }
        });
        b4.setOnClickListener(new View.OnClickListener() {

            public void onClick(View v) {
                myellow.start();
            }
        });
        b5.setOnClickListener(new View.OnClickListener() {

            public void onClick(View v) {
                mred.start();
            }
        });
        b6.setOnClickListener(new View.OnClickListener() {

            public void onClick(View v) {
                mgreen.start();
            }
        });

    }
}

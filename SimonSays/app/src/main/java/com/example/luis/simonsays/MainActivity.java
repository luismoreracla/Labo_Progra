package com.example.luis.simonsays;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button b1=(Button)findViewById(R.id.Play_Button);
        Button b2=(Button)findViewById(R.id.HS_button);


        /** Ir a actividad de jugar */
        b1.setOnClickListener(new View.OnClickListener() {

            public void onClick(View v) {
                Intent myintent2 = new Intent(getBaseContext(),Play_Game.class);
                startActivity(myintent2);

            }
        });

        /** Ir a actividad de high score*/
        b2.setOnClickListener(new View.OnClickListener() {

            public void onClick(View v) {
                Intent myintent2 = new Intent(getBaseContext(),High_Scores.class);
                startActivity(myintent2);

            }
        });
    }



}

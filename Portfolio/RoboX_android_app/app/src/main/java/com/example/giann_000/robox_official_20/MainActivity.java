package com.example.giann_000.robox_official_20;

import android.app.Fragment;
import android.app.FragmentManager;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;

import java.io.IOException;

public class MainActivity extends AppCompatActivity {

    ListView listview;
    ArrayAdapter<String> listAdapter;
    String fragmentArray[] = {"Fragment 1", "Fragment 2"};


    private String mac_address;
    private TextView tvConnStatus;
    private BluetoothConnection btConn;
    private Button btnForward, btnBackwards, btnLeft, btnRight, btnStop, btnUturnLeft, btnUturnRight, btnFaster, btnSlower, btnAuto;
    private TextView tvResult, tvSentData;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        listview = (ListView)findViewById(R.id.listview);
        listAdapter = new ArrayAdapter<String>(this,android.R.layout.simple_list_item_1, fragmentArray);
        listview.setAdapter(listAdapter);

       listview.setOnItemClickListener(new AdapterView.OnItemClickListener() {
           @Override
           public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
               Fragment fragment;
               switch (position) {
                   case 0:
                       fragment = new FragmentOne();
                       break;
                   default:
                       fragment = new FragmentOne();
                       break;
               }

               //android.support.v4.app.FragmentManager frag = getSupportFragmentManager();
               //frag.beginTransaction().replace(R.id.LinearLayout, fragment).commit();
           }
       });


        tvConnStatus = (TextView)findViewById(R.id.tvConnStatus);
        btnForward = (Button)findViewById(R.id.btnForward);
        btnBackwards = (Button)findViewById(R.id.btnBackwards);
        btnLeft = (Button)findViewById(R.id.btnLeft);
        btnRight = (Button)findViewById(R.id.btnRight);
        btnStop = (Button)findViewById(R.id.btnStop);
        btnUturnLeft = (Button)findViewById(R.id.btnUturnLeft);
        btnUturnRight = (Button)findViewById(R.id.btnUturnRight);
        btnFaster = (Button)findViewById(R.id.faster);
        btnSlower = (Button)findViewById(R.id.slower);
        tvResult = (TextView)findViewById(R.id.tvResult);
        tvSentData = (TextView)findViewById(R.id.tvSentData);
        btnAuto = (Button)findViewById(R.id.autoknop);

        btnForward.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    btConn.sendData("w");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
        btnBackwards.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    btConn.sendData("s");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
        btnLeft.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    btConn.sendData("a");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
        btnRight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    btConn.sendData("d");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
        btnStop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    btConn.sendData("x");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
        btnUturnLeft.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    btConn.sendData("n");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
        btnUturnRight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    btConn.sendData("m");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
        btnFaster.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    btConn.sendData("p");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
        btnSlower.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    btConn.sendData("o");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
        btnAuto.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    btConn.sendData("c");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });


    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);

        return true;
    }
    @Override
    public void onDestroy(){
        super.onDestroy();
        if(mac_address != ""){
            try {
                btConn.closeBT();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    @Override
    public void onResume(){
        super.onResume();
        Log.i("TAG", "before");
        try{
            Intent i = getIntent();
            mac_address = i.getStringExtra("mac address");
            ConnectToDevice();
        }
        catch (Exception e){
            Log.i("TAG",e.toString());
        }

    }

    private void ConnectToDevice() {
        btConn = new BluetoothConnection();
        btConn.Result(tvResult);
        btConn.SentData(tvSentData);
        tvConnStatus.setText("Connectionstatus: "+ btConn.Connect(mac_address));
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            Intent i = new Intent(MainActivity.this, BluetoothDeviceListActivity.class);
            startActivity(i);
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}

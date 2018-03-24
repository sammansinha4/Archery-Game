#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<iostream.h>
void target(int);
int menu();
int main();
void arrow(int,int,int);
void man(int,int);
int gdriver=DETECT,gmode,errorcode;
int i=0,k=0,score=0,initarrow=5,midx, midy, widthHome, heightHome,X, Y;
char z[4];
void instruction(){
    while(1){
        setcolor(RED);
        outtextxy(260,15,"Press `backspace' to go back");
        setcolor(GREEN);
        settextstyle(8,0,3);
        outtextxy(20,60,"1. Press SPACE to shoot the arrow");
        outtextxy(20,100,"2. Each player has five lives");
        outtextxy(20,140,"which is displayed by arrows above");
        outtextxy(20,180,"the archer");
        outtextxy(20,220,"3. After pressing the shoot button,");

        outtextxy(20,260,"players should wait until the");
        outtextxy(20,300,"target reappears from the top");

        int ch=getch();
        if(ch==8){//backspace
            cleardevice();
            closegraph();
            menu();

            }
    }
}




int gameover(){
    setcolor(0);
     setfillstyle(SOLID_FILL,0);
     bar(11,11,getmaxx()-11,getmaxy()-11);
     setcolor(BROWN);
     setfillstyle(SOLID_FILL,1);
     bar(getmaxx()/2-100,getmaxy()/2-50,getmaxx()/2+100,getmaxy()/2+50);//CENTER
     outtextxy(getmaxx()/2-50,getmaxy()/2-20,"Game Over!");
     outtextxy(getmaxx()/2-70,getmaxy()/2,"Your score is:");
     outtextxy(getmaxx()/2-200,getmaxy()/2+90,"Press `Space Bar' to Continue and `Esc' to Exit");
     gcvt(score,4,z);
     outtextxy(getmaxx()/2+60,getmaxy()/2,z);
    if(getch()==32){//DECREASES TOTAL NUMBER OF ARROWS TO 3 IN NEXT ROUND
        initarrow=3;
        score=0;
        main();
    }
    closegraph();

    exit(0);
    return 0;
}


int hit(int posi,int xk,int color){
             int xx=157+xk-2,yy=181+xk-2;//xk for correction of arrow and target touch
             setcolor(YELLOW);
             outtextxy(280,70,"Total Score:");
             gcvt(score,4,z);
             setcolor(color);
             outtextxy(360,70,z);
    for(i=i;i<=getmaxy();i++)
     {
      setfillstyle(1,6);//Pattern, Color
        bar(626,20+i,630,110+i);//largest bar
        setfillstyle(1,3);
        bar(621,30+i,625,100+i);
        setfillstyle(1,1);
        bar(616,40+i,620,90+i);
        setfillstyle(1,2);
        bar(611,50+i,615,80+i);
        setfillstyle(1,4);
        bar(606,60+i,610,70+i);//smallest bar
        //DISPLAYS ARROW ON BOARD
        if(posi>=93 && posi<103){
            setcolor(6);
            line(xx,203+i-posi,yy,203+i-posi);
        }
        if(posi>=103 && posi<113){
            setcolor(3);
            line(xx,203+i-posi,yy,203+i-posi);
        }
        if(posi>=113 && posi<123){
            setcolor(1);
            line(xx,203+i-posi,yy,203+i-posi);
        }
        if(posi>=123 && posi<133){
            setcolor(2);
            line(xx,203+i-posi,yy,203+i-posi);
        }
        if(posi>=133 && posi<143){
            setcolor(4);
            line(xx,203+i-posi,yy,203+i-posi);
        }
        if(posi>=143 && posi<153){
            setcolor(2);
            line(xx,203+i-posi,yy,203+i-posi);
        }

        if(posi>=153 && posi<163){
                setcolor(1);
            line(xx,203+i-posi,yy,203+i-posi);
        }
        if(posi>=163 && posi<173){
            setcolor(3);
            line(xx,203+i-posi,yy,203+i-posi);;
        }
        if(posi>=173 && posi<=183){
           setcolor(6);
           line(xx,203+i-posi,yy,203+i-posi);
        }
        delay(10);//Delay after the arrow hits the target
        setcolor(0);
        line(xx,203+i-posi,yy,203+i-posi);
        setfillstyle(SOLID_FILL,0);
        bar(626,20+i,630,110+i);
        bar(621,30+i,625,100+i);
        bar(616,40+i,620,90+i);
        bar(611,50+i,615,80+i);
        bar(606,60+i,610,70+i);
        //MOVING ARROW WITH TARGET(BOARD) ON HIT
        if(posi>=93 && posi<103){
                setfillstyle(1,4);
           line(xx,203+i-posi,yy,203+i-posi);
        }
        if(posi>=103 && posi<113){
            line(xx,203+i-posi,yy,203+i-posi);
        }
        if(posi>=113 && posi<123){
            line(xx,203+i-posi,yy,203+i-posi);
        }
        if(posi>=123 && posi<133){
            line(xx,203+i-posi,yy,203+i-posi);
        }
        if(posi>=133 && posi<143){
            line(xx,203+i-posi,yy,203+i-posi);
        }
        if(posi>=143 && posi<153){
            line(xx,203+i-posi,yy,203+i-posi);
        }

        if(posi>=153 && posi<163){
            line(xx,203+i-posi,yy,203+i-posi);
        }
        if(posi>=163 && posi<173){
            line(xx,203+i-posi,yy,203+i-posi);;
        }
        if(posi>=173 && posi<=183){
            line(xx,203+i-posi,yy,203+i-posi);
        }

        if(kbhit()){
            int ch=getch();
            if(ch==27){
                closegraph();
                exit(0);
            }
        }

  }
  //FOR DISPLAYING THE CURRENT POINTS
      i=0;k=0;
      setcolor(0);
     if(posi>=93 && posi<103){
         outtextxy(300,40,"Points: 20");
        }
        if(posi>=103 && posi<113){
            outtextxy(300,40,"Points: 40");
        }
        if(posi>=113 && posi<123){
            outtextxy(300,40,"Points: 60");
        }
        if(posi>=123 && posi<133){
            outtextxy(300,40,"Points: 80");
        }
        if(posi>=133 && posi<143){
            outtextxy(300,40,"Points: 100");
        }
        if(posi>=143 && posi<153){
            outtextxy(300,40,"Points: 80");
        }

        if(posi>=153 && posi<163){
            outtextxy(300,40,"Points: 60");
        }
        if(posi>=163 && posi<173){
            outtextxy(300,40,"Points: 40");
        }
        if(posi>=173 && posi<=183){
            outtextxy(300,40,"Points: 20");
        }
target(initarrow);
return 0;

}



void shoot(){
    char ch;
    if(initarrow==0){
        gameover();
    }
     initarrow-=1;//DECREASES LIFE OR ARROW ON shoot() call
     //DISAPPEAR ARROW:SIMPLY REPLACING WITH BLACK COLOR IN SAME POSITION ON FOLLOWING CONDITION
     if(initarrow==4){
          arrow(0,0,4);
          arrow(15,15,4);
          arrow(30,30,4);
          arrow(45,45,4);
          arrow(60,60,0);
     }
     if(initarrow==3){
          arrow(0,0,4);
          arrow(15,15,4);
          arrow(30,30,4);
          arrow(45,45,0);
          arrow(60,60,0);

     }
     if(initarrow==2){
          arrow(0,0,4);
          arrow(15,15,4);
          arrow(30,30,0);
          arrow(45,45,0);
          arrow(60,60,0);
     }
     if(initarrow==1){
          arrow(0,0,4);
          arrow(15,15,0);
          arrow(30,30,0);
          arrow(45,45,0);
          arrow(60,60,0);
     }
     if(initarrow==0){
          arrow(0,0,0);
          arrow(15,15,0);
          arrow(30,30,0);
          arrow(45,45,0);
          arrow(60,60,0);
     }
    gcvt(score,4,z);//STORE DECIMAL SCORE IN Z(ARRAY) AS STRING
    a:
    setcolor(LIGHTGRAY);
     for(i=i;i<=getmaxy();i++){
        setcolor(LIGHTGRAY);
        if(k==450 && i>=93 && i<103){//k=POSITON OF ARROW[HORIZONTAL] & i=POSITION OF DARTBOARD[(TARGET)VERTICAL]
            score=score+20;
            setcolor(6);
            outtextxy(300,40,"Points: 20");
            hit(i,k,6);
        }
        if(k==445 && i>=103 && i<113){
            score=score+40;
            setcolor(3);
            outtextxy(300,40,"Points: 40");
            hit(i,k,3);
        }
        if(k==440 && i>=113 && i<123){
            score=score+60;
            setcolor(1);
            outtextxy(300,40,"Points: 60");
            hit(i,k,1);
        }
        if(k==435 && i>=123 && i<133){
            score=score+80;
            setcolor(2);
            outtextxy(300,40,"Points: 80");
            hit(i,k,2);
        }
        if(k==430 && i>=133 && i<143){
            score=score+100;
            setcolor(4);
            outtextxy(300,40,"Points: 100");
            hit(i,k,4);
        }
        if(k==435 && i>=143 && i<153){
            score=score+80;
            setcolor(2);
            outtextxy(300,40,"Points: 80");
            hit(i,k,2);
        }

        if(k==440 && i>=153 && i<163){
            score=score+60;
            setcolor(1);
            outtextxy(300,40,"Points: 60");
            hit(i,k,1);
        }
        if(k==445 && i>=163 && i<173){
            score=score+40;
            setcolor(3);
            outtextxy(300,40,"Points: 40");
            hit(i,k,3);
        }
        if(k==450 && i>=173 && i<=183){
            score=score+20;
            setcolor(6);
            outtextxy(300,40,"Points: 20");
            hit(i,k,6);
        }
        if(k>=500){
            k=0;
            target(initarrow);
        }

        //TO DISPLAY THE TARGET ONCE SHOOT BUTTON IS PRESSED
        setfillstyle(1,6);
        setcolor(LIGHTGREEN);
        bar(626,20+i,630,110+i);//largest bar
        setfillstyle(1,3);
        bar(621,30+i,625,100+i);
        setfillstyle(1,1);
        bar(616,40+i,620,90+i);
        setfillstyle(1,2);
        bar(611,50+i,615,80+i);
        setfillstyle(1,4);
        bar(606,60+i,610,70+i);//smallest bar
        line(157+k,203,181+k,203);
        delay(10);
        //REPLACES ABOVE FIGURE WITH BLACK
        //USED INSTEAD OF cleardevice()
        setcolor(0);
        setfillstyle(SOLID_FILL,0);
        bar(626,20+i,630,110+i);
        bar(621,30+i,625,100+i);
        bar(616,40+i,620,90+i);
        bar(611,50+i,615,80+i);
        bar(606,60+i,610,70+i);
        line(157+k,203,181+k,203);
        k=k+5;

 }

     i=0;
     goto a;
}



//DISPLAY DARTBOA RD
void target(int initarrow1)
{
    if(initarrow1==0){
        gameover();
    }

         int dely=10;//Delay of the target
         a:
         for(i=i;i<=getmaxy();i++)
         {

        setfillstyle(1,6);
        bar(626,20+i,630,110+i);//largest bar
        setfillstyle(1,3);
        bar(621,30+i,625,100+i);
        setfillstyle(1,1);
        bar(616,40+i,620,90+i);
        setfillstyle(1,2);
        bar(611,50+i,615,80+i);
        setfillstyle(1,4);
        bar(606,60+i,610,70+i);//smallest bar
        delay(dely);
        //REPLACE WITH BLACK
        setfillstyle(SOLID_FILL,0);
        bar(626,20+i,630,110+i);
        bar(621,30+i,625,100+i);
        bar(616,40+i,620,90+i);
        bar(611,50+i,615,80+i);
        bar(606,60+i,610,70+i);

        if(kbhit())//ON KEY PRESS
        {
            int ch=getch();
            if(ch==27)//Escape
            {
                closegraph();
                exit(0);
            }
            if(ch==32)//Space
            {
                shoot();  //shoot();
            }
        }

    }
 i=0;
 goto a;
}




//DISPLAY ARCHER
void man(int x, int y){ //CHANGE IN X AND Y TO MOVE ARCHER POSITION
    setcolor(LIGHTGREEN);
    setfillstyle(SOLID_FILL,LIGHTGREEN);
         line(x+69,y+365,x+68,y+358);// left thigh start
         line(x+69,y+359,x+68,y+351);
         line(x+69,y+349,x+69,y+342);
         line(x+70,y+341,x+69,y+339);
         line(x+70,y+337,x+73,y+333);
         line(x+73,y+331,x+74,y+330);
         line(x+76,y+328,x+71,y+325);// left thigh
         line(x+72,y+324,x+75,y+318);//back bone part
         line(x+75,y+317,x+76,y+308);
         line(x+77,y+307,x+75,y+301);
         line(x+76,y+300,x+71,y+293);
         line(x+72,y+292,x+67,y+288);
         line(x+70,y+288,x+63,y+285);
         line(x+66,y+284,x+58,y+288);
         line(x+61,y+286,x+55,y+289);//back bone
         line(x+57,y+290,x+47,y+287);//left hand elbow s
         line(x+49,y+286,x+43,y+284);
         line(x+45,y+283,x+42,y+282);
         line(x+42,y+281,x+45,y+276);
         line(x+47,y+273,x+53,y+273);
         line(x+45,y+276,x+47,y+273);
         line(x+54,y+272,x+54,y+270);// left hand elbow
         line(x+54,y+268,x+58,y+267);//arrow bag
         line(x+55,y+267,x+55,y+267);
         line(x+60,y+265,x+61,y+264);
         line(x+60,y+264,x+60,y+264);
         line(x+59,y+264,x+59,y+264);
         line(x+62,y+263,x+66,y+263);
         line(x+60,y+264,x+58,y+265);//arrow bag
         line(x+67,y+262,x+72,y+266);
         line(x+68,y+261,x+68,y+261);
         line(x+68,y+261,x+68,y+261);
         line(x+73,y+265,x+74,y+266);
         line(x+75,y+265,x+76,y+264);//head s
         line(x+75,y+262,x+69,y+258);
         line(x+69,y+256,x+68,y+255);
         line(x+68,y+254,x+67,y+253);
         line(x+67,y+251,x+67,y+248);
        line(x+68,y+248,x+67,y+247);
        line(x+67,y+246,x+69,y+243);
        line(x+68,y+243,x+71,y+240);
        line(x+70,y+240,x+75,y+238);
        line(x+74,y+237,x+80,y+236);
        line(x+79,y+235,x+85,y+236);
        line(x+85,y+235,x+89,y+238);//head e
        line(x+89,y+236,x+91,y+243);// face part s
        line(x+91,y+239,x+92,y+249);
        line(x+93,y+249,x+93,y+250);
        line(x+92,y+248,x+94,y+254);
        line(x+94,y+249,x+96,y+262);
        line(x+97,y+259,x+97,y+264);
        line(x+97,y+261,x+100,y+265);
        line(x+98,y+263,x+101,y+265);// face part e
        line(x+96,y+263,x+104,y+266);// right hand top
        line(x+104,y+265,x+106,y+265);
        line(x+107,y+264,x+109,y+264);
        line(x+111,y+263,x+116,y+266);
        line(x+111,y+260,x+111,y+260);
        line(x+111,y+260,x+111,y+260);
        line(x+111,y+263,x+111,y+263);
        line(x+108,y+263,x+112,y+264);
        line(x+171,y+264,x+118,y+267);
        line(x+70,y+364,x+70,y+368);
        line(x+69,y+363,x+71,y+373);// right hand top
        line(x+71,y+371,x+72,y+373);
        line(x+72,y+371,x+74,y+375);//left knee
        line(x+74,y+375,x+77,y+376);
        line(x+78,y+376,x+82,y+375);
        line(x+81,y+376,x+88,y+371);
        line(x+86,y+372,x+92,y+368);
        line(x+94,y+362,x+92,y+366);
        line(x+95,y+360,x+95,y+361);
        line(x+93,y+365,x+91,y+369);
        line(x+96,y+360,x+98,y+366);// left knee
        line(x+99,y+365,x+95,y+370);
        line(x+97,y+368,x+93,y+373);
        line(x+93,y+373,x+94,y+375);
        line(x+95,y+375,x+99,y+375);
        line(x+102,y+375,x+108,y+374);
        line(x+101,y+375,x+99,y+375);
        line(x+106,y+374,x+109,y+371);
        line(x+110,y+369,x+106,y+365);
        line(x+110,y+369,x+109,y+372);
        line(x+107,y+364,x+107,y+357);
        line(x+90,y+353,x+98,y+349);
        line(x+98,y+350,x+101,y+347);
        line(x+101,y+347,x+105,y+349);
        line(x+104,y+347,x+107,y+351);
        line(x+108,y+357,x+107,y+352);
        line(x+91,y+351,x+90,y+349);//left leg
        line(x+90,y+351,x+92,y+344);
        line(x+92,y+343,x+96,y+341);
        line(x+97,y+339,x+101,y+336);
        line(x+103,y+335,x+103,y+335);
        line(x+103,y+335,x+103,y+335);
        line(x+101,y+337,x+107,y+337);//right leg
        line(x+106,y+337,x+117,y+336);
        line(x+114,y+337,x+122,y+336);
        line(x+118,y+372,x+120,y+364);
        line(x+120,y+362,x+122,y+357);
        line(x+122,y+357,x+122,y+352);
        line(x+123,y+351,x+122,y+345);
        line(x+123,y+337,x+121,y+346);
        line(x+117,y+372,x+118,y+374);//right foot
        line(x+118,y+374,x+120,y+374);
        line(x+119,y+375,x+126,y+375);
        line(x+126,y+375,x+131,y+375);
        line(x+133,y+375,x+140,y+375);//bottom right foot
        line(x+134,y+375,x+131,y+375);
         outtextxy(x+126,y+380,"Archer");
        line(x+140,y+375,x+149,y+375);
        line(x+149,y+375,x+148,y+375);
        line(x+145,y+376,x+152,y+374);
        line(x+153,y+372,x+153,y+370);
        line(x+154,y+370,x+150,y+369);
        line(x+152,y+368,x+146,y+369);
        line(x+148,y+368,x+137,y+367);
        line(x+140,y+364,x+140,y+364);
        line(x+140,y+364,x+140,y+364);
        line(x+140,y+366,x+136,y+364);
        line(x+139,y+366,x+135,y+364);
        line(x+141,y+347,x+136,y+353);
        line(x+136,y+353,x+135,y+358);
        line(x+135,y+357,x+136,y+362);
        line(x+142,y+347,x+142,y+342);
        line(x+142,y+341,x+145,y+334);
        line(x+145,y+335,x+146,y+327);
        line(x+146,y+329,x+146,y+318);
        line(x+147,y+317,x+141,y+315);
        line(x+143,y+315,x+129,y+313);//line 138 - 151 right stomach
        line(x+134,y+313,x+124,y+313);
        line(x+127,y+312,x+121,y+312);
        line(x+109,y+299,x+112,y+305);
        line(x+112,y+304,x+115,y+309);
        line(x+117,y+309,x+121,y+312);
        line(x+118,y+309,x+115,y+307);
        line(x+109,y+298,x+111,y+290);
        line(x+111,y+291,x+111,y+285);
        line(x+111,y+286,x+118,y+283);
        line(x+118,y+282,x+131,y+282);
        line(x+130,y+282,x+143,y+280);
        line(x+143,y+279,x+153,y+277);
        line(x+153,y+278,x+163,y+277);
        line(x+161,y+276,x+166,y+276);
        line(x+162,y+276,x+171,y+279);
        line(x+173,y+278,x+176,y+278);
        line(x+172,y+278,x+173,y+278);
        setcolor(RED);
        setfillstyle(SOLID_FILL,RED);// bow
        line(x+107,y+171,x+117,y+176);
        line(x+117,y+176,x+123,y+180);
        line(x+123,y+180,x+130,y+184);
        line(x+130,y+184,x+139,y+193);
        line(x+139,y+193,x+145,y+202);
        line(x+145,y+202,x+152,y+211);
        line(x+152,y+211,x+157,y+222);
        line(x+158,y+222,x+162,y+235);
        line(x+163,y+235,x+166,y+247);
        line(x+166,y+247,x+169,y+262);
        line(x+141,y+358,x+149,y+352);
        line(x+149,y+352,x+155,y+345);
        line(x+155,y+345,x+160,y+337);
        line(x+160,y+337,x+163,y+330);
        line(x+163,y+330,x+166,y+324);
        line(x+166,y+325,x+170,y+309);
        line(x+169,y+310,x+171,y+295);
        line(x+171,y+297,x+171,y+278);
        line(x+141,y+358,x+147,y+358);
        line(x+147,y+358,x+156,y+350);
        line(x+156,y+350,x+163,y+341);
        line(x+163,y+341,x+170,y+328);
        line(x+170,y+329,x+173,y+315);
        line(x+173,y+316,x+176,y+302);
        line(x+176,y+302,x+177,y+285);
        line(x+177,y+285,x+176,y+279);
        line(x+176,y+260,x+173,y+246);
        line(x+108,y+170,x+113,y+170);
        line(x+113,y+170,x+120,y+172);
        line(x+120,y+172,x+125,y+175);
        line(x+125,y+175,x+130,y+179);
        line(x+130,y+179,x+137,y+185);
        line(x+137,y+185,x+141,y+189);
        line(x+141,y+189,x+148,y+196);
        line(x+148,y+196,x+153,y+203);
        line(x+153,y+203,x+158,y+213);
        line(x+155,y+205,x+164,y+222);
        line(x+164,y+220,x+172,y+247);
        line(x+172,y+247,x+172,y+244);
        line(x+54,y+269,x+49,y+265);
        line(x+49,y+265,x+44,y+262);
        line(x+44,y+262,x+43,y+260);
        line(x+43,y+260,x+44,y+261);
        line(x+44,y+259,x+44,y+258);
        line(x+44,y+258,x+46,y+256);
        line(x+46,y+256,x+51,y+259);
        line(x+51,y+259,x+53,y+263);
        line(x+53,y+264,x+53,y+264);
        line(x+53,y+261,x+54,y+264);
        line(x+54,y+259,x+48,y+255);
        line(x+48,y+254,x+47,y+252);
        line(x+48,y+251,x+52,y+250);
        line(x+52,y+250,x+57,y+256);
        line(x+57,y+256,x+55,y+258);
        line(x+57,y+256,x+59,y+260);
        line(x+59,y+260,x+61,y+262);
        line(x+55,y+258,x+60,y+264);
        line(x+61,y+256,x+64,y+261);
        line(x+52,y+245,x+57,y+244);
        line(x+57,y+244,x+60,y+248);
        line(x+61,y+248,x+63,y+251);
        line(x+63,y+251,x+63,y+253);
        line(x+63,y+253,x+68,y+261);
        line(x+61,y+254,x+56,y+254);
        line(x+59,y+253,x+52,y+250);
        line(x+52,y+250,x+52,y+244);
        line(x+178,y+263,x+182,y+263);//arrow head
        line(x+182,y+263,x+183,y+262);
        line(x+183,y+261,x+192,y+264);
        line(x+183,y+263,x+192,y+264);//point
        line(x+192,y+264,x+185,y+268);
        line(x+183,y+265,x+184,y+268);
        line(x+184,y+265,x+177,y+265);
        setcolor(LIGHTGREEN);
        setfillstyle(SOLID_FILL,LIGHTGREEN);
        line(x+177,y+278,x+180,y+272);
        line(x+180,y+272,x+178,y+266);
}


//PRINT ARROW ON SCREEN
void arrow(int xp, int yp, int col)
{
    setcolor(col);
    setfillstyle(SOLID_FILL,col);
    //Arrow
    line(xp+5,yp+5,xp+100,yp+5);

    //Buttom
    int upperFletching[8] = {xp+0,xp+1,xp+5,xp+5,yp+15,yp+5,yp+10,yp+1};
    fillpoly(4, upperFletching);

    int lowerFletcting[8] = {xp+5,xp+5,xp+15,xp+5,yp+10,yp+9,yp+0,yp+9};
    fillpoly(4, lowerFletcting);

    //tip
    int tip[6] = {xp+90,xp+2,xp+100,yp+5,yp+90,yp+8};
    fillpoly(3, tip);
}



//MAIN MENU
int menu()
{   //fflush(stdin);
    initgraph(&gdriver,&gmode,"C://TurboC3//BGI");
    char sX[10], sY[10];
    char a[4];

    midx = getmaxx()/2;
    midy = getmaxy()/2;

	   char ch;
       setcolor(RED);
       rectangle(221,79,419,106);
    //MENU SELECTION
    while(1){
       switch(getch()){
	    case 27:
		exit(0);
	    case 13:
		cleardevice();
		closegraph();
		initgraph(&gdriver,&gmode,"C://TurboC3//BGI");
		arrow(0,0,4);
		arrow(15,15,4);
		arrow(30,30,4);
		arrow(45,45,4);
		arrow(60,60,4);
		man(-30,-60);
		setcolor(4);
		setfillstyle(SOLID_FILL,4);
		bar(48,422,63,435);
		outtextxy(74,420,"->100 pt");
		setcolor(2);
		setfillstyle(SOLID_FILL,2);
		bar(150,422,165,435);
		outtextxy(176,420,"->80 pt");
		setcolor(1);
		setfillstyle(SOLID_FILL,1);
		bar(252,422,267,435);
		outtextxy(278,420,"->60 pt");
		setcolor(3);
		setfillstyle(SOLID_FILL,3);
		bar(354,422,369,435);
		outtextxy(380,420,"->40 pt");
		setcolor(6);
		setfillstyle(SOLID_FILL,6);
		bar(456,422,471,435);
		outtextxy(482,420,"->20 pt");
		setcolor(RED);
		outtextxy(480,15,"Press `Esc' to Quit");
		setcolor(YELLOW);
		outtextxy(280,70,"Total Score:");
		gcvt(score,4,z);
		outtextxy(360,70,z);
		target(initarrow);
		break;

	    case 80:
		setcolor(RED);//ASCII for down
		rectangle(221,114,420,147);
		setcolor(BLACK);
		rectangle(221,79,419,106);
		ch=getch();
		if (ch==13) {
		    cleardevice();
		    instruction();
		    }
		if(ch==72){
		    setcolor(BLACK);
		    rectangle(221,114,420,147);
		    setcolor(RED);
		    rectangle(221,79,419,106);
		}
		if(ch==80){
		    setcolor(BLACK);//ASCII for down
		    rectangle(221,114,420,147);
		    setcolor(RED);
		    rectangle(221,79,419,106);
		}
		break;
	    case 72://ASCII for up
		setcolor(BLACK);
		rectangle(221,114,420,147);
		setcolor(RED);
		rectangle(221,79,419,106);
		break;

	}
    }

}




int main()
{


    //DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
     //DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
     //std::cout<< screenWidth << std::endl;//1366
    // std::cout<< screenHeight << std::endl;//768
     // initwindow(getmaxx(),getmaxy(),"Mediavel Archery",360,150);
    menu();
    getch();
    return 0;

}
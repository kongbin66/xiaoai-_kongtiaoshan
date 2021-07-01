#include <Arduino.h>
#define BLINKER_PRINT Serial
#define BLINKER_MIOT_LIGHT
#define BLINKER_WIFI

#include <Blinker.h>

//秘钥
#if 1
char auth[] = "f82cf05d3d63";   //换成APP获取到的密匙
char ssid[] = "UROBEI";          //WiFi账号
char pswd[] = "UROBEI123";   //WIFI密码
#else
char auth[] = "f82cf05d3d63";   //空调扇
char ssid[] = "anlengkj";          //WiFi账号
char pswd[] = "al77776666";   //WIFI密码
#endif

//端口
#define KTMS 2      //空调模式
#define SFMS 4      //扫风模式
#define DI 5        //I
#define ZHONG 15    //II
#define GAO 18      //III
#define CAOQIANG 19 //IIII





//#define BUTTON_1 "ButtonKey"


//组件对象
BlinkerButton Button0("btn_0");     //空调
BlinkerButton Button1("btn_1");      //一档
BlinkerButton Button2("btn_2");     //二档
BlinkerButton Button3("btn_3");     //三挡
BlinkerButton Button4("btn_4");     //四挡
BlinkerButton Button5("btn_5");     //停机
BlinkerButton Button6("btn_6");      //扫风


bool F_BUTT0 = false;
bool F_BUTT1 = false;


//空调
void button0_callback(const String & state)
{
    BLINKER_LOG("get button state: ", state);
    Serial.printf("in button0:%s\n",state);

    //Blinker.vibrate(); 
    if (state=="on") 
    {
        Serial.println("on\n");
        
        // 反馈开关状态
        Button0.print("on");
        digitalWrite(KTMS, HIGH);
    } 
    else if(state=="off")
    {
        Serial.println("off\n");
        
        // 反馈开关状态
        Button0.print("off");
        digitalWrite(KTMS, LOW);
    }
}




void button1_callback(const String & state)//一档
{
    BLINKER_LOG("get button state: ", state);
    Serial.printf("in button1:%s\n",state);

    //Blinker.vibrate(); 
    if (state=="tap") 
    {
        Serial.println("tap\n");
        
        // 反馈开关状态
        Button1.print("on");
        digitalWrite(DI,HIGH);
        digitalWrite(ZHONG,LOW);
        digitalWrite(GAO,LOW);
        digitalWrite(CAOQIANG,LOW);
    } 
}




void button2_callback(const String & state)//二档
{
    BLINKER_LOG("get button state: ", state);
    Serial.printf("in button2:%s\n",state);

    //Blinker.vibrate(); 
    if (state=="tap") 
    {
        Serial.println("tap\n");
        
        // 反馈开关状态
        Button2.print("on");
        digitalWrite(DI,LOW);
        digitalWrite(ZHONG,HIGH);
        digitalWrite(GAO,LOW);
        digitalWrite(CAOQIANG,LOW);
    } 
}
void button3_callback(const String & state)//三档
{
    BLINKER_LOG("get button state: ", state);
    Serial.printf("in button3:%s\n",state);

    //Blinker.vibrate(); 
    if (state=="tap") 
    {
        Serial.println("tap\n");
        
        // 反馈开关状态
        Button3.print("on");
        digitalWrite(DI,LOW);
        digitalWrite(ZHONG,LOW);
        digitalWrite(GAO,HIGH);
        digitalWrite(CAOQIANG,LOW);
    } 
}
void button4_callback(const String & state)//四档
{
    BLINKER_LOG("get button state: ", state);
    Serial.printf("in button4:%s\n",state);

    //Blinker.vibrate(); 
    if (state=="tap") 
    {
        Serial.println("tap\n");
        
        // 反馈开关状态
        Button4.print("on");
        digitalWrite(DI,LOW);
        digitalWrite(ZHONG,LOW);
        digitalWrite(GAO,LOW);
        digitalWrite(CAOQIANG,HIGH);
    } 
}

void button5_callback(const String & state)//停机
{
    BLINKER_LOG("get button state: ", state);
    Serial.printf("in button5:%s\n",state);

    //Blinker.vibrate(); 
    if (state=="tap") 
    {
        Serial.println("tap\n");
        
        // 反馈开关状态
        Button5.print("on");
        digitalWrite(KTMS,LOW);
        digitalWrite(SFMS,LOW);
        digitalWrite(DI,LOW);
        digitalWrite(ZHONG,LOW);
        digitalWrite(GAO,LOW);
        digitalWrite(CAOQIANG,LOW);
    } 
}
//扫风
void button6_callback(const String & state)
{
    BLINKER_LOG("get button state: ", state);
    Serial.printf("in button6:%s\n",state);

    //Blinker.vibrate(); 
    if (state=="on") 
    {
        Serial.println("on\n");
        
        // 反馈开关状态
        Button6.print("on");
        digitalWrite(SFMS, HIGH);
    } 
    else if(state=="off")
    {
        Serial.println("off\n");
        
        // 反馈开关状态
        Button6.print("off");
        digitalWrite(SFMS, LOW);
    }
}

//设置模式
void miotMode(uint8_t mode)
{
    BLINKER_LOG("need set mode: ", mode);

    if (mode == BLINKER_CMD_MIOT_DAY) {//空调
        // Your mode function
        Serial.printf("in button0\n");
        F_BUTT0=!F_BUTT0;
        if(F_BUTT0)
        {
            Button0.print("on");
            digitalWrite(KTMS,HIGH);
        }
        else
        {
            Button0.print("off");
            digitalWrite(KTMS,LOW);
        }
    }
    else if (mode == BLINKER_CMD_MIOT_NIGHT) {//扫风
        // Your mode function
        Serial.printf("in button6\n");
        F_BUTT1=!F_BUTT1;
        if(F_BUTT1)
        {
            Button6.print("on");
            digitalWrite(SFMS,HIGH);
        }
        else
        {
            Button6.print("off");
            digitalWrite(SFMS,LOW);
        }
    }
    else if (mode == BLINKER_CMD_MIOT_COLOR) {//停机
        // Your mode function
        Serial.printf("in button5\n");
        digitalWrite(KTMS,LOW);
        digitalWrite(SFMS,LOW);
        digitalWrite(DI,LOW);
        digitalWrite(ZHONG,LOW);
        digitalWrite(GAO,LOW);
        digitalWrite(CAOQIANG,LOW);
    }
    else if (mode == BLINKER_CMD_MIOT_WARMTH) {//1当
        // Your mode function
        Serial.printf("in button1\n");
        digitalWrite(DI,HIGH);
        digitalWrite(ZHONG,LOW);
        digitalWrite(GAO,LOW);
        digitalWrite(CAOQIANG,LOW);
    }
    else if (mode == BLINKER_CMD_MIOT_TV) {//二挡
        // Your mode function
        Serial.printf("in button2\n");
        digitalWrite(DI,LOW);
        digitalWrite(ZHONG,HIGH);
        digitalWrite(GAO,LOW);
        digitalWrite(CAOQIANG,LOW);
    }
    else if (mode == BLINKER_CMD_MIOT_READING) {//三挡
        // Your mode function
        Serial.printf("in button3\n");
        digitalWrite(DI,LOW);
        digitalWrite(ZHONG,LOW);
        digitalWrite(GAO,HIGH);
        digitalWrite(CAOQIANG,LOW);
    }
    else if (mode == BLINKER_CMD_MIOT_COMPUTER) {//四档
        // Your mode function
        Serial.printf("in button4\n");
        digitalWrite(DI,LOW);
        digitalWrite(ZHONG,LOW);
        digitalWrite(GAO,LOW);
        digitalWrite(CAOQIANG,HIGH);
    }

    //wsMode = mode;

    BlinkerMIOT.mode(mode);
    BlinkerMIOT.print();
}



void setup() {
    Serial.begin(115200);
  
    pinMode(2,OUTPUT);
    digitalWrite(2,LOW);//初始化，由于继电器是低电平触发。所以刚开始设为高电平
    pinMode(4,OUTPUT);
    digitalWrite(4,LOW);
    pinMode(5,OUTPUT);
    digitalWrite(5,LOW);
    pinMode(15,OUTPUT);
    digitalWrite(15,LOW);
    pinMode(18,OUTPUT);
    digitalWrite(18,LOW);
    pinMode(19,OUTPUT);
    digitalWrite(19,LOW);
   
    Blinker.begin(auth, ssid, pswd);
    BlinkerMIOT.attachMode(miotMode);
    Button0.attach(button0_callback);//空调
    Button1.attach(button1_callback);//一档
    Button2.attach(button2_callback);//二档
    Button3.attach(button3_callback);//三档
    Button4.attach(button4_callback);//四档
    Button5.attach(button5_callback);//停机档
    Button6.attach(button6_callback);//扫风
    // BlinkerMIOT.attachPowerState(miotPowerState);//这段代码一定要加，不加小爱同学控制不了,务必在回调函数中反馈该控制状态


}

void loop()
{
    Blinker.run();
}
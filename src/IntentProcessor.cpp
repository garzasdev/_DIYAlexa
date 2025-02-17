#include <Arduino.h>
#include "IntentProcessor.h"
#include "Speaker.h"
#include <WiFi.h>
#include "PubSubClient.h"

PubSubClient _MQTTClient;
WiFiClient _WIFI;

IntentProcessor::IntentProcessor(Speaker *speaker)
{
    m_speaker = speaker;
}

IntentResult IntentProcessor::turnOnDevice(const Intent &intent)
{
    if (intent.intent_confidence < 0.8)
    {
        Serial.printf("Only %.f%% certain on intent\n", 100 * intent.intent_confidence);
        return FAILED;
    }
    if (intent.device_name.empty())
    {
        Serial.println("No device found");
        return FAILED;
    }
    if (intent.device_confidence < 0.8)
    {
        Serial.printf("Only %.f%% certain on device\n", 100 * intent.device_confidence);
        return FAILED;
    }
    if (intent.trait_value.empty())
    {
        Serial.println("Can't work out the intent action");
        return FAILED;
    }
    if (intent.trait_confidence < 0.8)
    {
        Serial.printf("Only %.f%% certain on trait\n", 100 * intent.trait_confidence);
        return FAILED;
    }
    bool is_turn_on = intent.trait_value == "on";

    // global device name "lights"
    if (intent.device_name == "lights")
    {
        for (const auto &dev_pin : m_device_to_pin)
        {
            digitalWrite(dev_pin.second, is_turn_on);
        }
    }
    else
    {
        // see if the device name is something we know about
        if (m_device_to_pin.find(intent.device_name) == m_device_to_pin.end())
        {
            Serial.printf("Don't recognise the device '%s'\n", intent.device_name.c_str());
            return FAILED;
        }
        digitalWrite(m_device_to_pin[intent.device_name], is_turn_on);
    }
    // success!
    return SUCCESS;
}

IntentResult IntentProcessor::tellJoke()
{
    m_speaker->playRandomJoke();
    return SILENT_SUCCESS;
}

IntentResult IntentProcessor::life()
{
    m_speaker->playLife();
    return SILENT_SUCCESS;
}

IntentResult IntentProcessor::processIntent(const Intent &intent)
{
    byte _MAC[6];
    bool CommandRecognized = false;
    char _ClientID[8] = "\0";
    char *_MQTTCommand1 = new char[128];
    char *_MQTTCommand2 = new char[128];
    char *_MQTTTopic1 = new char[128];
    char *_MQTTTopic2 = new char[128];

    WiFi.macAddress(_MAC);
    sprintf(_ClientID, "%02X%02X%02X", _MAC[3], _MAC[4], _MAC[5]);
    _MQTTClient.setClient(_WIFI);
    _MQTTClient.setServer("192.168.3.8", 1883);
    if (!_MQTTClient.connect(_ClientID))
    {
        Serial.println("Cound not connect to MQTT");
        return FAILED;
    }

    if (intent.text.empty())
    {
        Serial.println("No text recognised");
        return FAILED;
    }
    Serial.printf("I heard \"%s\"\n", intent.text.c_str());
    if (intent.intent_name.empty())
    {
        Serial.println("Can't work out what you want to do with the device...");
        return FAILED;
    }
    Serial.printf("Intent is %s\n", intent.intent_name.c_str());
    if (intent.intent_name == "Turn_on_device")
    {
        return turnOnDevice(intent);
    }
    if (intent.intent_name == "Tell_joke")
    {
        return tellJoke();
    }
    if (intent.intent_name == "Life")
    {
        return life();
    }
    if (intent.intent_name == "RaiseShades")
    {
        if (intent.device_name == "living room")
        {
            strcpy(_MQTTCommand1,"{\"SRC\":\"VA\",\"DST\":\"C8C9A333CD65\", \"RST\":2,\"VBL\":\"MOVESHADE\",\"VAL\":\"UP\"}");
            strcpy(_MQTTTopic1, "/Home/Comm/C8C9A333CD65/");
            strcpy(_MQTTCommand2,"{\"SRC\":\"VA\",\"DST\":\"C8C9A334D962\", \"RST\":2,\"VBL\":\"MOVESHADE\",\"VAL\":\"UP\"}");
            strcpy(_MQTTTopic2, "/Home/Comm/C8C9A334D962/");
            CommandRecognized = true;
        }
        if (intent.device_name == "north")
        {
            
        }
        if (intent.device_name == "east")
        {
            
        }
        if (intent.device_name == "south")
        {
            
        }
        if (intent.device_name == "west")
        {
            
        }
        if (intent.device_name == "second floor")
        {
            
        }
        if (intent.device_name == "first floor")
        {
            
        }
        if (intent.device_name == "main floor")
        {
            
        }
        if (intent.device_name == "master bedroom")
        {
            strcpy(_MQTTCommand1,"{\"SRC\":\"VA\",\"DST\":\"08F9E05FB923\", \"RST\":2,\"VBL\":\"MOVESHADE\",\"VAL\":\"UP\"}");
            strcpy(_MQTTTopic1, "/Home/Comm/08F9E05FB923/");
            strcpy(_MQTTCommand2,"{\"SRC\":\"VA\",\"DST\":\"C8C9A33527C6\", \"RST\":2,\"VBL\":\"MOVESHADE\",\"VAL\":\"UP\"}");
            strcpy(_MQTTTopic2, "/Home/Comm/C8C9A33527C6/");
            CommandRecognized = true;
        }
        if (intent.device_name == "basement")
        {
            
        }
        if (intent.device_name == "bedroom")
        {
            
        }
    }
    if (intent.intent_name == "LowerShades")
    {
        if (intent.device_name == "living room")
        {
            strcpy(_MQTTCommand1,"{\"SRC\":\"VA\",\"DST\":\"C8C9A333CD65\", \"RST\":2,\"VBL\":\"MOVESHADE\",\"VAL\":\"DOWN\"}");
            strcpy(_MQTTTopic1, "/Home/Comm/C8C9A333CD65/");
            strcpy(_MQTTCommand2,"{\"SRC\":\"VA\",\"DST\":\"C8C9A334D962\", \"RST\":2,\"VBL\":\"MOVESHADE\",\"VAL\":\"DOWN\"}");
            strcpy(_MQTTTopic2, "/Home/Comm/C8C9A334D962/");
            CommandRecognized = true;
        }
        if (intent.device_name == "master bedroom")
        {
            strcpy(_MQTTCommand1,"{\"SRC\":\"VA\",\"DST\":\"08F9E05FB923\", \"RST\":2,\"VBL\":\"MOVESHADE\",\"VAL\":\"DOWN\"}");
            strcpy(_MQTTTopic1, "/Home/Comm/08F9E05FB923/");
            strcpy(_MQTTCommand2,"{\"SRC\":\"VA\",\"DST\":\"C8C9A33527C6\", \"RST\":2,\"VBL\":\"MOVESHADE\",\"VAL\":\"DOWN\"}");
            strcpy(_MQTTTopic2, "/Home/Comm/C8C9A33527C6/");
            CommandRecognized = true;
        }
    }
    if (intent.intent_name == "OpenGarage")
    {
Serial.printf("Entity: %s\n", intent.device_name.c_str());
    }
    if (intent.intent_name == "CloseGarage")
    {
Serial.printf("Entity: %s\n", intent.device_name.c_str());
    }

    _MQTTClient.publish(_MQTTTopic1, _MQTTCommand1);
    _MQTTClient.loop();
    _MQTTClient.publish(_MQTTTopic2, _MQTTCommand2);
    _MQTTClient.loop();
    _MQTTClient.disconnect();

    delete [] _MQTTCommand1;
    delete [] _MQTTCommand2;
    delete [] _MQTTTopic1;
    delete [] _MQTTTopic2;

    if (CommandRecognized) return SUCCESS;
    return FAILED;
}

void IntentProcessor::addDevice(const std::string &name, int gpio_pin)
{
    m_device_to_pin.insert(std::make_pair(name, gpio_pin));
    pinMode(gpio_pin, OUTPUT);
}

/*
	Aatt.cpp - Library for sending data to aatt server
	@author Patrick Hoolboom
	@date 9/24/2013
*/

#include <Arduino.h>
#include <Ethernet.h>
#include <SPI.h>
#include <Aatt.h>
#include <aJSON.h>

//aJsonStream serial_stream(&Serial);
aJsonObject *payload;
aJsonObject *auth;
aJsonObject *data;
aJsonObject *records;
aJsonObject *checks;

Aatt::Aatt() {
	const char* _url;
	int _port;
	payload = aJson.createObject();
	aJson.addItemToObject(payload,"AUTH",auth = aJson.createObject());
	aJson.addItemToObject(payload,"DATA",data = aJson.createObject());
	records = aJson.createObject();
	checks = aJson.createObject();
}

void Aatt::setSyncUrl(const char* url, int port) {
	_url = url;
	_port = port;
}

void Aatt::setAccount(const char* account, const char* key) {
	aJson.addStringToObject(auth,"APP","aatt_arduino");
	aJson.addStringToObject(auth,"ACCOUNT",account);
	aJson.addStringToObject(auth,"KEY",key);
}

void Aatt::setDevice(const char* device_id) {
	aJson.addStringToObject(data,"DEVICE",device_id);
}

void Aatt::setAct(const char* act) {
	aJson.addStringToObject(payload,"ACT", act);
	if(strcmp(act,"RECORD") == 0){
		aJson.addItemToObject(data,"RECORDS",records);
	}else if(strcmp(act,"CHECK") == 0){
		aJson.addItemToObject(data,"CHECKS",records);
	}
}

void Aatt::record(const char* endpoint, const char* value) {
	aJson.addStringToObject(records,endpoint,value);
}

void Aatt::check(const char* endpoint, const char* attribute) {
	aJson.addStringToObject(checks,endpoint,attribute);
}

char* Aatt::getPayload(){
	return aJson.print(payload);
}

void Aatt::send(){
	//Do stuff
}
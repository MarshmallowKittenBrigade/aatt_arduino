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

Aatt::Aatt() {
	const char* _url;
	int _port;
	const char* _act;
	const char* action;
	aJsonObject* _payload = aJson.createObject();
	aJsonObject* _auth = aJson.createObject();
	aJsonObject* _data = aJson.createObject();
	aJsonObject* _records = aJson.createObject();
	aJsonObject* _checks = aJson.createObject();
}

void Aatt::setSyncUrl(const char* url, int port) {
	_url = url;
	_port = port;
}

void Aatt::setAccount(const char* account, const char* key) {
	aJson.addStringToObject(_auth,"APP","aatt_arduino");
	aJson.addStringToObject(_auth,"ACCOUNT",account);
	aJson.addStringToObject(_auth,"KEY",key);
}

void Aatt::setDevice(const char* device_id) {
	aJson.addStringToObject(_data,"DEVICE",device_id);
}

void Aatt::setAct(const char* act) {
	action = act;
	aJson.addStringToObject(_payload,"ACT", act);
}

void Aatt::record(const char* endpoint, const char* value) {
	aJson.addStringToObject(_records,endpoint,value);
}

void Aatt::check(const char* endpoint, const char* attribute) {
	aJson.addStringToObject(_checks,endpoint,attribute);
}

void Aatt::compile() {

	if(strcmp(action,"RECORD") == 0){
		aJson.addItemToObject(_data,"RECORDS",_records);
	}else if(strcmp(action,"CHECK") == 0){
		aJson.addItemToObject(_data,"CHECKS",_checks);
	}

	aJson.addItemToObject(_payload,"AUTH",_auth);
	aJson.addItemToObject(_payload,"DATA",_data);

}

char* Aatt::send(){
	this->compile();
	return Json.print(_payload);
}
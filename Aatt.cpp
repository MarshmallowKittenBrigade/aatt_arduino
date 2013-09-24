/*
	Aatt.cpp - Library for sending data to aatt server
	@author Patrick Hoolboom
	@date 9/24/2013
*/

#include <Arduino.h>
#include <Ethernet.h>
#include <SPI.h>
#include <Aatt.h>

Aatt::Aatt() {
	String _url;
	int _port;
	String _account;
	String _key;
	int _device_id;
	String _device;
	String _act;
	String _payload;
	String _data;
}

void Aatt::setSyncUrl(String url, int port) {
	_url = url;
	_port = port;
}

void Aatt::setAccount(String account, String key) {
	_account = account;
	_key = key;
	_auth += '"APP":"aatt_arduino",';
	_auth += '"ACCOUNT":"';
	_auth += _account;
	_auth += '","KEY":"';
	_auth += _key;
	_auth += '"';
}

void Aatt::setDevice(int device_id) {
	_device_id = device_id;
	_data += '"DEVICE":"';
	_data += _device_id;
	_data += '"';
}

void Aatt::setAct(String act) {
	_act = '"ACT":"';
	_act += act;
	_act += '"';

	if(strcmp(act, "RECORD")) {
		_data += ',"RECORDS:{';
	}else if (strcmp(act, "CHECK")) {
		_data += ',"CHECKS:{';
	}
}

void Aatt::record(int endpoint, String value) {
	_data += '"';
	_data += endpoint;
	_data += '":"';
	_data += value;
	_data += '",';
}

void Aatt::check(int endpoint, int attribute) {

}

void Aatt::compile() {

	_data = _data.substring(0, inString.length() - 1);
	_data += '}';

	_payload = '{';
	_payload += '"AUTH":{';
	_payload += _auth;
	_payload += '},';
	_payload += _act;
	_payload += ',';
	_payload += '"DATA:{';
	_payload += _data;
	_payload += '}';

}

String Aatt::send(){
	return _payload;
}
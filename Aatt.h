/*
	Aatt.h - Library for sending data to aatt server
	@author Patrick Hoolboom
	@date 9/24/2013
*/
#ifndef Aatt_h
#define Aatt_h

#include <Arduino.h>
#include <Ethernet.h>
#include <SPI.h>
#include <aJSON.h>

class Aatt {
	
	public:
		Aatt();
		void setSyncUrl(const char* url, int port);
		void setAccount(const char* account,const char* key);
		void setDevice(const char* device_id);
		void setAct(const char* act);
		void record(const char* endpoint, const char* value);
		void check(const char* endpoint, const char* attribute);
		char* send();
	private:
		void compile();
		const char* _url;
		int _port;
		const char* action;
		aJsonObject* _payload;
		aJsonObject* _auth;
		aJsonObject* _data;
		aJsonObject* _records;
		aJsonObject* _checks;
};

#endif
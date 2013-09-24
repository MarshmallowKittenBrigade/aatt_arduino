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

class Aatt {
	
	public:
		Aatt();
		void setSyncUrl(String url, int port);
		void setAccount(String account,String key);
		void setDevice(int device_id);
		void setAct(String act);
		void record(int endpoint, String value);
		void check(int endpoint, int attribute);
		String send();
	private:
		void compile();
		String _url;
		int _port;
		String _account;
		String _key;
		int _device_id;
		String _act;
};

#endif
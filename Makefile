all:
	g++ -o String_Oper String_Oper.cc Mylogger.cc -llog4cpp -lpthread -std=c++11

clean:
	rm -f String_Oper

#include <pistache/endpoint.h>
#include "libs/json.hpp"
#include "websocketpp/server.hpp"

using namespace Pistache;
using namespace std;
using nlohmann::json; 

struct ConsumersUser {
	string user_icon; 
	string user_name; 
	int user_level; 
};

void to_json(json &j, const ConsumersUser &t) {
	j = json{{"user_icon", t.user_icon},
		{"user_name", t.user_name},
		{"user_level", t.user_level}};
}

struct ConsumersGroup {
	string group_icon; 
	string group_name; 
	int group_level; 
}; 

void to_json(json &j, const ConsumersGroup &t) {
	j = json{{"group_icon", t.group_icon},
		{"group_name", t.group_name},
		{"group_level", t.group_level}};
}

struct Data {
	long int date;
	int userConsumption;
	int groupConsumption;
	int selfSufficiency;
	ConsumersUser consumersUser;
	ConsumersGroup consumersGroup;
};

void to_json(json &j, const Data &t) {
	j = json{{"date", t.date},
		{"userConsumption", t.userConsumption},
		{"groupConsumption", t.groupConsumption},
		{"selfSufficiency", t.selfSufficiency},
		{"consumersUser", t.consumersUser},
		{"consumersGroup", t.consumersGroup}};
}

json generate_live_data() {
    	long int date = static_cast<long int>(time(0));
	int userConsumption = rand() % 4000;
	int groupConsumption = rand() % 50000;
	int selfSufficiency = rand() % 100 + 1; 
	string user_icon = "testuser";
	string user_name = "Harry Potter";
	int user_level = rand() % 100;
	string group_icon = "testgroup";
	string group_name = "Hogwarts";
	int group_level = rand() % 100;
	ConsumersUser consumersUser = ConsumersUser{user_icon, user_name, user_level};
	ConsumersGroup consumersGroup = ConsumersGroup{group_icon, group_name, group_level};
	return json(Data{date, userConsumption, groupConsumption, selfSufficiency, json(consumersUser), json(consumersGroup)});
}

class HelloBuzzn : public Http::Handler {
public: 
	HTTP_PROTOTYPE(HelloBuzzn)
	void onRequest(const Http::Request& request, Http::ResponseWriter response) override {
		UNUSED(request);
		response.send(Pistache::Http::Code::Ok, "Welcome to  My BUZZN!\n");
	}
	
};

int main() {
	Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(9080));
	auto opts = Pistache::Http::Endpoint::options().threads(1);
	Http::Endpoint server(addr);
	server.init(opts);
	server.setHandler(Http::make_handler<HelloBuzzn>());
	server.serve();
} 

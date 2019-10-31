#include <pistache/endpoint.h>

using namespace Pistache;

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

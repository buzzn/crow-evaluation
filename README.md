# pistache-evaluation
My BUZZN minimal backend prototype.

## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites
* [Boost](https://www.boost.org/) 

## Built With
* C++11
* [Pistache](https://github.com/oktal/pistache/)
* [Websocket++](https://github.com/zaphoyd/websocketpp)

## Run
g++ -L/usr/lib -lpistache -lpthread app.cpp -o app
./app
http://localhost:9080

## Acknowledgements
* [oktal/pistache/examples](https://github.com/oktal/pistache/tree/master/examples)

## Known Issues
* https://github.com/oktal/pistache/issues/217
* https://github.com/zaphoyd/websocketpp/issues/843

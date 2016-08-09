/* TODO: LICENSE HEADER */
#include <stdio.h>

#include <stdio.h>
#include<conio.h>

//include the generated files
#include "../gen-cpp/types_constants.h"

//include the libtecs-cpp files
#include <tecs-2/ps/PSFactory.hpp>
//TECSClient namespace
//using namespace de::dfki::tecs::ps;
//BaseTypes Namespace
//using namespace de::dfki::tecs;

//Namespace used in the genrated files in this example "HelloWorldEvent"
//using namespace de::dfki::tecs::examples::helloworld;

int main() {
	{
		/*//Open a Connection with id cpp-client
		std::unique_ptr<misc::URI> uri = PSFactory::createURI("cpp-client", "localhost", 9000);

		printf("URI is: %s\n", uri->toString().c_str());
		std::unique_ptr<PSClient> sender = PSFactory::createPSClient(*uri);

		client->subscribe("HelloWorldEvent");
		client->connect();

		//Test the ping functionallity
		printf("Ping is %lld\n", client->ping("cpp-client", 1000));
		printf("Ping is %lldd\n", client->ping("no-client", 1000));


		{//Test sending
			printf("Sending HelloWorldEvent\n");
			HelloWorldEvent * hwe = new HelloWorldEvent();
			hwe->message = "Hello World";
			client->send(".*", "HelloWorldEvent", hwe);
			delete hwe;
		}

		//Test Receiving
		while (client->isOnline()) {
			while (client->canRecv()) {
				std::shared_ptr<Event> event = client->recv();
				printf("Received: %s from %s addressed to %s at %lld\n", event->getEtype().c_str(), event->getSource().c_str(), event->getTarget().c_str(), event->getTime());

				if (event->is("HelloWorldEvent")) {
					std::shared_ptr<HelloWorldEvent> hwe(new HelloWorldEvent());
					event->parseData(hwe);
					printf("Message: %s\n", hwe->message.c_str());
					client->disconnect();
					break;
				}
			}
		}
	}*/

	printf("Successfully disconnected and shutdown\n");
	return 0;
}

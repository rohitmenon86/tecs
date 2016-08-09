/* TODO: LICENSE HEADER */
#include <stdio.h>
#include<conio.h>

//include the generated files
#include "../gen-cpp/types_constants.h"

//include the libtecs-cpp files
#include <tecs-2/ps/PSFactory.hpp>

//TECSClient namespace
using namespace de::dfki::tecs::ps;
//BaseTypes Namespace
using namespace de::dfki::tecs;

//Namespace used in the genrated files in this example "HelloWorldEvent"
using namespace de::dfki::tecs::examples::helloworld;

int main() {
  {
    //Open a Connection with id cpp-client
    std::unique_ptr<misc::URI> uri = PSFactory::createURI("windowssend", "ilaadr-ur10", 9000);

    printf ("URI is: %s\n", uri->toString().c_str()); 
    std::unique_ptr<PSClient> sender = PSFactory::createPSClient(*uri);
	
    sender->subscribe("HelloWorldWindows");
	sender->connect();
	//Test the ping functionallity
    printf("Ping is %lld\n", sender->ping("windowssend", 1000));
    printf("Ping is %lldd\n", sender->ping("no-client", 1000));
	
	std::unique_ptr<misc::URI> uri2 = PSFactory::createURI("windowsrec", "ilaadr-ur10", 9000);

	printf("URI is: %s\n", uri2->toString().c_str());
	std::unique_ptr<PSClient> receiver = PSFactory::createPSClient(*uri2);

	receiver->subscribe("HelloWorldLinux");
	receiver->connect();
	//Test the ping functionallity
	printf("Ping is %lld\n", receiver->ping("windowsrec", 1000));
	printf("Ping is %lldd\n", receiver->ping("no-client", 1000));
    //Test Receiving
    while (receiver->isOnline()) {
        while (receiver->canRecv()) {
            std::shared_ptr<Event> event = receiver->recv();
            printf("Received: %s from %s addressed to %s at %lld\n", event->getEtype().c_str(), event->getSource().c_str(), event->getTarget().c_str(), event->getTime());

            if (event->is("HelloWorldLinux")) {
                std::shared_ptr<HelloWorldEvent> hwe (new HelloWorldEvent());
                event->parseData(hwe);
                printf("Message: %s\n", hwe->message.c_str());
				receiver->disconnect();
                break;
            }
        }
    }

	for (int i = 0; i<200; i++)
	{//Test sending
		printf("Sending HelloWorldEvent\n");
		HelloWorldEvent * hwe = new HelloWorldEvent();
		hwe->message = "Hello World from Windows";
		sender->send(".*", "HelloWorldWindows", hwe);
		delete hwe;
		Sleep(2000);
	}
  }
  _getch();
    printf("Successfully disconnected and shutdown\n");
    return 0;
}

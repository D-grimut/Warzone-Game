#include "LoggingObserver.h"
#include "GameEngine.h"
#include "CommandProcessing.h"
#include "Orders.h"
#include "FileCommandProcessorAdapter.h"

int main()
{
    LogObserver *ol = new LogObserver();

    GameEngine *engine = new GameEngine();
    Command *command = new Command();
    Command *command2 = new Command();
    Command *command3 = new Command();
    CommandProcessor *cp = new CommandProcessor();
    Order *deploy = new Deploy();
    Order *advance = new Advance();
    Order *bomb = new Bomb();
    Order *blockade = new Blockade();
    Order *airlift = new Airlift();
    Order *negotiate = new Negotiate();

    int size = 6;
    OrdersList *list = new OrdersList(&size);

    list->attach(ol);
    engine->attach(ol);
    command->attach(ol);
    command2->attach(ol);
    command3->attach(ol);
    cp->attach(ol);
    deploy->attach(ol);
    advance->attach(ol);
    bomb->attach(ol);
    blockade->attach(ol);
    airlift->attach(ol);
    negotiate->attach(ol);

    // //Adding all orders to list - PRINTS TO LOG
    list->addOrder(deploy, 0);
    list->addOrder(advance, 1);
    list->addOrder(bomb, 2);
    list->addOrder(blockade, 3);
    list->addOrder(airlift, 4);
    list->addOrder(negotiate, 5);

    // Executing all orders - PRINTS TO LOG
    list->execute();

    // Transitioning - PRINTS TO LOG
    engine->TransitionTo(1);
    engine->TransitionTo(2);
    engine->TransitionTo(3);
    engine->TransitionTo(4);
    engine->TransitionTo(5);
    engine->TransitionTo(6);
    engine->TransitionTo(7);
    // engine->TransitionTo(8);

    // Adding effect to dummy command - PRINTS TO LOG
    command->saveEffect("Test effect - 1");
    command2->saveEffect("Test effect - 2");
    command3->saveEffect("Test effect - 3");

    // Getting command from cp - PRINTS TO LOG
    cp->getCommand();
    cp->getCommand();
    cp->getCommand();

    FileCommandProcessorAdapter *test = new FileCommandProcessorAdapter("gamelog.txt");
    std::string str;
    test->attach(ol);
    while (str != "EOF")
    {
        str = test->readCommand();
        std::cout << str << std::endl;
    }

    return 0;
}
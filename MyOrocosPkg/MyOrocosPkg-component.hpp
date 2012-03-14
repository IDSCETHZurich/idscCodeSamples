#ifndef OROCOS_MYOROCOSPKG_COMPONENT_HPP
#define OROCOS_MYOROCOSPKG_COMPONENT_HPP

#include <rtt/RTT.hpp>
#include <iostream>
#include <MyROSPkg/typekit/mySpecialMsg.h>

class MyOrocosComponent
    : public RTT::TaskContext
{
 public:
    MyROSPkg::mySpecialMsg msgFromROS;
    MyOrocosComponent(string const& name)
        : TaskContext(name)
    {
        std::cout << "MyOrocosPkg constructed !" <<std::endl;
	this->addPort("spInputPort", sp_inputPort);
	this->addPort("spOutputPort", sp_outputPort);
    }

    bool configureHook() {
        std::cout << "MyOrocosPkg configured !" <<std::endl;
        return true;
    }

    bool startHook() {
        std::cout << "MyOrocosPkg started !" <<std::endl;
        return true;
    }

    void updateHook() {
	sp_inputPort.read(msgFromROS);
	sp_outputPort.write(msgFromROS);
	
        //std::cout << "MyOrocosPkg executes updateHook !" <<std::endl;
	//std::cout << "msgFromROS -> A = " <<  msgFromROS.A << " , B = " << msgFromROS.B; 
    }

    void stopHook() {
        std::cout << "MyOrocosPkg executes stopping !" <<std::endl;
    }

    void cleanupHook() {
        std::cout << "MyOrocosPkg cleaning up !" <<std::endl;
    }
 protected:
	
	RTT::InputPort<MyROSPkg::mySpecialMsg> sp_inputPort;
	RTT::OutputPort<MyROSPkg::mySpecialMsg> sp_outputPort;
};

#endif

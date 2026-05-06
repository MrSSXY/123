// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for quadrotor_msgs/TRPYCommand
#include "boost/date_time.hpp"
#include "boost/shared_array.hpp"
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 4265)
#pragma warning(disable : 4458)
#pragma warning(disable : 4100)
#pragma warning(disable : 4127)
#pragma warning(disable : 4267)
#pragma warning(disable : 4068)
#pragma warning(disable : 4245)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif //_MSC_VER
#include "ros/ros.h"
#include "quadrotor_msgs/TRPYCommand.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_msg_TRPYCommand_common : public MATLABROSMsgInterface<quadrotor_msgs::TRPYCommand> {
  public:
    virtual ~quadrotor_msgs_msg_TRPYCommand_common(){}
    virtual void copy_from_struct(quadrotor_msgs::TRPYCommand* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const quadrotor_msgs::TRPYCommand* msg, MultiLibLoader loader, size_t size = 1);
};
  void quadrotor_msgs_msg_TRPYCommand_common::copy_from_struct(quadrotor_msgs::TRPYCommand* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //header
        const matlab::data::StructArray header_arr = arr["Header"];
        auto msgClassPtr_header = getCommonObject<std_msgs::Header>("std_msgs_msg_Header_common",loader);
        msgClassPtr_header->copy_from_struct(&msg->header,header_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Header' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Header' is wrong type; expected a struct.");
    }
    try {
        //thrust
        const matlab::data::TypedArray<float> thrust_arr = arr["Thrust"];
        msg->thrust = thrust_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Thrust' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Thrust' is wrong type; expected a single.");
    }
    try {
        //roll
        const matlab::data::TypedArray<float> roll_arr = arr["Roll"];
        msg->roll = roll_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Roll' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Roll' is wrong type; expected a single.");
    }
    try {
        //pitch
        const matlab::data::TypedArray<float> pitch_arr = arr["Pitch"];
        msg->pitch = pitch_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Pitch' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Pitch' is wrong type; expected a single.");
    }
    try {
        //yaw
        const matlab::data::TypedArray<float> yaw_arr = arr["Yaw"];
        msg->yaw = yaw_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Yaw' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Yaw' is wrong type; expected a single.");
    }
    try {
        //aux
        const matlab::data::StructArray aux_arr = arr["Aux"];
        auto msgClassPtr_aux = getCommonObject<quadrotor_msgs::AuxCommand>("quadrotor_msgs_msg_AuxCommand_common",loader);
        msgClassPtr_aux->copy_from_struct(&msg->aux,aux_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Aux' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Aux' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T quadrotor_msgs_msg_TRPYCommand_common::get_arr(MDFactory_T& factory, const quadrotor_msgs::TRPYCommand* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Header","Thrust","Roll","Pitch","Yaw","Aux"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("quadrotor_msgs/TRPYCommand");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::Header>("std_msgs_msg_Header_common",loader);
    outArray[ctr]["Header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // thrust
    auto currentElement_thrust = (msg + ctr)->thrust;
    outArray[ctr]["Thrust"] = factory.createScalar(currentElement_thrust);
    // roll
    auto currentElement_roll = (msg + ctr)->roll;
    outArray[ctr]["Roll"] = factory.createScalar(currentElement_roll);
    // pitch
    auto currentElement_pitch = (msg + ctr)->pitch;
    outArray[ctr]["Pitch"] = factory.createScalar(currentElement_pitch);
    // yaw
    auto currentElement_yaw = (msg + ctr)->yaw;
    outArray[ctr]["Yaw"] = factory.createScalar(currentElement_yaw);
    // aux
    auto currentElement_aux = (msg + ctr)->aux;
    auto msgClassPtr_aux = getCommonObject<quadrotor_msgs::AuxCommand>("quadrotor_msgs_msg_AuxCommand_common",loader);
    outArray[ctr]["Aux"] = msgClassPtr_aux->get_arr(factory, &currentElement_aux, loader);
    }
    return std::move(outArray);
  } 
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_TRPYCommand_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~quadrotor_msgs_TRPYCommand_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          quadrotor_msgs_TRPYCommand_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<quadrotor_msgs::TRPYCommand,quadrotor_msgs_msg_TRPYCommand_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         quadrotor_msgs_TRPYCommand_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<quadrotor_msgs::TRPYCommand,quadrotor_msgs::TRPYCommand::ConstPtr,quadrotor_msgs_msg_TRPYCommand_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         quadrotor_msgs_TRPYCommand_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<quadrotor_msgs::TRPYCommand,quadrotor_msgs_msg_TRPYCommand_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_msg_TRPYCommand_common, MATLABROSMsgInterface<quadrotor_msgs::TRPYCommand>)
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_TRPYCommand_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1
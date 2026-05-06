// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for quadrotor_msgs/Gains
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
#include "quadrotor_msgs/Gains.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_msg_Gains_common : public MATLABROSMsgInterface<quadrotor_msgs::Gains> {
  public:
    virtual ~quadrotor_msgs_msg_Gains_common(){}
    virtual void copy_from_struct(quadrotor_msgs::Gains* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const quadrotor_msgs::Gains* msg, MultiLibLoader loader, size_t size = 1);
};
  void quadrotor_msgs_msg_Gains_common::copy_from_struct(quadrotor_msgs::Gains* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //Kp
        const matlab::data::TypedArray<double> Kp_arr = arr["Kp"];
        msg->Kp = Kp_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Kp' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Kp' is wrong type; expected a double.");
    }
    try {
        //Kd
        const matlab::data::TypedArray<double> Kd_arr = arr["Kd"];
        msg->Kd = Kd_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Kd' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Kd' is wrong type; expected a double.");
    }
    try {
        //Kp_yaw
        const matlab::data::TypedArray<double> Kp_yaw_arr = arr["KpYaw"];
        msg->Kp_yaw = Kp_yaw_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'KpYaw' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'KpYaw' is wrong type; expected a double.");
    }
    try {
        //Kd_yaw
        const matlab::data::TypedArray<double> Kd_yaw_arr = arr["KdYaw"];
        msg->Kd_yaw = Kd_yaw_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'KdYaw' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'KdYaw' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T quadrotor_msgs_msg_Gains_common::get_arr(MDFactory_T& factory, const quadrotor_msgs::Gains* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Kp","Kd","KpYaw","KdYaw"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("quadrotor_msgs/Gains");
    // Kp
    auto currentElement_Kp = (msg + ctr)->Kp;
    outArray[ctr]["Kp"] = factory.createScalar(currentElement_Kp);
    // Kd
    auto currentElement_Kd = (msg + ctr)->Kd;
    outArray[ctr]["Kd"] = factory.createScalar(currentElement_Kd);
    // Kp_yaw
    auto currentElement_Kp_yaw = (msg + ctr)->Kp_yaw;
    outArray[ctr]["KpYaw"] = factory.createScalar(currentElement_Kp_yaw);
    // Kd_yaw
    auto currentElement_Kd_yaw = (msg + ctr)->Kd_yaw;
    outArray[ctr]["KdYaw"] = factory.createScalar(currentElement_Kd_yaw);
    }
    return std::move(outArray);
  } 
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_Gains_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~quadrotor_msgs_Gains_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          quadrotor_msgs_Gains_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<quadrotor_msgs::Gains,quadrotor_msgs_msg_Gains_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         quadrotor_msgs_Gains_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<quadrotor_msgs::Gains,quadrotor_msgs::Gains::ConstPtr,quadrotor_msgs_msg_Gains_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         quadrotor_msgs_Gains_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<quadrotor_msgs::Gains,quadrotor_msgs_msg_Gains_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_msg_Gains_common, MATLABROSMsgInterface<quadrotor_msgs::Gains>)
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_Gains_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1
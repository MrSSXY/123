// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for quadrotor_msgs/Odometry
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
#include "quadrotor_msgs/Odometry.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_msg_Odometry_common : public MATLABROSMsgInterface<quadrotor_msgs::Odometry> {
  public:
    virtual ~quadrotor_msgs_msg_Odometry_common(){}
    virtual void copy_from_struct(quadrotor_msgs::Odometry* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const quadrotor_msgs::Odometry* msg, MultiLibLoader loader, size_t size = 1);
};
  void quadrotor_msgs_msg_Odometry_common::copy_from_struct(quadrotor_msgs::Odometry* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //curodom
        const matlab::data::StructArray curodom_arr = arr["Curodom"];
        auto msgClassPtr_curodom = getCommonObject<nav_msgs::Odometry>("nav_msgs_msg_Odometry_common",loader);
        msgClassPtr_curodom->copy_from_struct(&msg->curodom,curodom_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Curodom' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Curodom' is wrong type; expected a struct.");
    }
    try {
        //kfodom
        const matlab::data::StructArray kfodom_arr = arr["Kfodom"];
        auto msgClassPtr_kfodom = getCommonObject<nav_msgs::Odometry>("nav_msgs_msg_Odometry_common",loader);
        msgClassPtr_kfodom->copy_from_struct(&msg->kfodom,kfodom_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Kfodom' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Kfodom' is wrong type; expected a struct.");
    }
    try {
        //kfid
        const matlab::data::TypedArray<uint32_t> kfid_arr = arr["Kfid"];
        msg->kfid = kfid_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Kfid' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Kfid' is wrong type; expected a uint32.");
    }
    try {
        //status
        const matlab::data::TypedArray<uint8_t> status_arr = arr["Status"];
        msg->status = status_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Status' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Status' is wrong type; expected a uint8.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T quadrotor_msgs_msg_Odometry_common::get_arr(MDFactory_T& factory, const quadrotor_msgs::Odometry* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","STATUSODOMVALID","STATUSODOMINVALID","STATUSODOMLOOPCLOSURE","Curodom","Kfodom","Kfid","Status"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("quadrotor_msgs/Odometry");
    // STATUS_ODOM_VALID
    auto currentElement_STATUS_ODOM_VALID = (msg + ctr)->STATUS_ODOM_VALID;
    outArray[ctr]["STATUSODOMVALID"] = factory.createScalar(static_cast<uint8_t>(currentElement_STATUS_ODOM_VALID));
    // STATUS_ODOM_INVALID
    auto currentElement_STATUS_ODOM_INVALID = (msg + ctr)->STATUS_ODOM_INVALID;
    outArray[ctr]["STATUSODOMINVALID"] = factory.createScalar(static_cast<uint8_t>(currentElement_STATUS_ODOM_INVALID));
    // STATUS_ODOM_LOOPCLOSURE
    auto currentElement_STATUS_ODOM_LOOPCLOSURE = (msg + ctr)->STATUS_ODOM_LOOPCLOSURE;
    outArray[ctr]["STATUSODOMLOOPCLOSURE"] = factory.createScalar(static_cast<uint8_t>(currentElement_STATUS_ODOM_LOOPCLOSURE));
    // curodom
    auto currentElement_curodom = (msg + ctr)->curodom;
    auto msgClassPtr_curodom = getCommonObject<nav_msgs::Odometry>("nav_msgs_msg_Odometry_common",loader);
    outArray[ctr]["Curodom"] = msgClassPtr_curodom->get_arr(factory, &currentElement_curodom, loader);
    // kfodom
    auto currentElement_kfodom = (msg + ctr)->kfodom;
    auto msgClassPtr_kfodom = getCommonObject<nav_msgs::Odometry>("nav_msgs_msg_Odometry_common",loader);
    outArray[ctr]["Kfodom"] = msgClassPtr_kfodom->get_arr(factory, &currentElement_kfodom, loader);
    // kfid
    auto currentElement_kfid = (msg + ctr)->kfid;
    outArray[ctr]["Kfid"] = factory.createScalar(currentElement_kfid);
    // status
    auto currentElement_status = (msg + ctr)->status;
    outArray[ctr]["Status"] = factory.createScalar(currentElement_status);
    }
    return std::move(outArray);
  } 
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_Odometry_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~quadrotor_msgs_Odometry_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          quadrotor_msgs_Odometry_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<quadrotor_msgs::Odometry,quadrotor_msgs_msg_Odometry_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         quadrotor_msgs_Odometry_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<quadrotor_msgs::Odometry,quadrotor_msgs::Odometry::ConstPtr,quadrotor_msgs_msg_Odometry_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         quadrotor_msgs_Odometry_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<quadrotor_msgs::Odometry,quadrotor_msgs_msg_Odometry_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_msg_Odometry_common, MATLABROSMsgInterface<quadrotor_msgs::Odometry>)
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_Odometry_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1
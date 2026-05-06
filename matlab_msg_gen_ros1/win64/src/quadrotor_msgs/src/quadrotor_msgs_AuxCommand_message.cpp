// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for quadrotor_msgs/AuxCommand
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
#include "quadrotor_msgs/AuxCommand.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_msg_AuxCommand_common : public MATLABROSMsgInterface<quadrotor_msgs::AuxCommand> {
  public:
    virtual ~quadrotor_msgs_msg_AuxCommand_common(){}
    virtual void copy_from_struct(quadrotor_msgs::AuxCommand* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const quadrotor_msgs::AuxCommand* msg, MultiLibLoader loader, size_t size = 1);
};
  void quadrotor_msgs_msg_AuxCommand_common::copy_from_struct(quadrotor_msgs::AuxCommand* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //current_yaw
        const matlab::data::TypedArray<double> current_yaw_arr = arr["CurrentYaw"];
        msg->current_yaw = current_yaw_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'CurrentYaw' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'CurrentYaw' is wrong type; expected a double.");
    }
    try {
        //kf_correction
        const matlab::data::TypedArray<double> kf_correction_arr = arr["KfCorrection"];
        msg->kf_correction = kf_correction_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'KfCorrection' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'KfCorrection' is wrong type; expected a double.");
    }
    try {
        //angle_corrections
        const matlab::data::TypedArray<double> angle_corrections_arr = arr["AngleCorrections"];
        size_t nelem = 2;
        	std::copy(angle_corrections_arr.begin(), angle_corrections_arr.begin()+nelem, msg->angle_corrections.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'AngleCorrections' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'AngleCorrections' is wrong type; expected a double.");
    }
    try {
        //enable_motors
        const matlab::data::TypedArray<bool> enable_motors_arr = arr["EnableMotors"];
        msg->enable_motors = enable_motors_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'EnableMotors' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'EnableMotors' is wrong type; expected a logical.");
    }
    try {
        //use_external_yaw
        const matlab::data::TypedArray<bool> use_external_yaw_arr = arr["UseExternalYaw"];
        msg->use_external_yaw = use_external_yaw_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'UseExternalYaw' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'UseExternalYaw' is wrong type; expected a logical.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T quadrotor_msgs_msg_AuxCommand_common::get_arr(MDFactory_T& factory, const quadrotor_msgs::AuxCommand* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","CurrentYaw","KfCorrection","AngleCorrections","EnableMotors","UseExternalYaw"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("quadrotor_msgs/AuxCommand");
    // current_yaw
    auto currentElement_current_yaw = (msg + ctr)->current_yaw;
    outArray[ctr]["CurrentYaw"] = factory.createScalar(currentElement_current_yaw);
    // kf_correction
    auto currentElement_kf_correction = (msg + ctr)->kf_correction;
    outArray[ctr]["KfCorrection"] = factory.createScalar(currentElement_kf_correction);
    // angle_corrections
    auto currentElement_angle_corrections = (msg + ctr)->angle_corrections;
    outArray[ctr]["AngleCorrections"] = factory.createArray<quadrotor_msgs::AuxCommand::_angle_corrections_type::const_iterator, double>({currentElement_angle_corrections.size(),1}, currentElement_angle_corrections.begin(), currentElement_angle_corrections.end());
    // enable_motors
    auto currentElement_enable_motors = (msg + ctr)->enable_motors;
    outArray[ctr]["EnableMotors"] = factory.createScalar(static_cast<bool>(currentElement_enable_motors));
    // use_external_yaw
    auto currentElement_use_external_yaw = (msg + ctr)->use_external_yaw;
    outArray[ctr]["UseExternalYaw"] = factory.createScalar(static_cast<bool>(currentElement_use_external_yaw));
    }
    return std::move(outArray);
  } 
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_AuxCommand_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~quadrotor_msgs_AuxCommand_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          quadrotor_msgs_AuxCommand_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<quadrotor_msgs::AuxCommand,quadrotor_msgs_msg_AuxCommand_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         quadrotor_msgs_AuxCommand_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<quadrotor_msgs::AuxCommand,quadrotor_msgs::AuxCommand::ConstPtr,quadrotor_msgs_msg_AuxCommand_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         quadrotor_msgs_AuxCommand_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<quadrotor_msgs::AuxCommand,quadrotor_msgs_msg_AuxCommand_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_msg_AuxCommand_common, MATLABROSMsgInterface<quadrotor_msgs::AuxCommand>)
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_AuxCommand_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1
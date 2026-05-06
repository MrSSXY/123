// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for quadrotor_msgs/LQRTrajectory
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
#include "quadrotor_msgs/LQRTrajectory.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_msg_LQRTrajectory_common : public MATLABROSMsgInterface<quadrotor_msgs::LQRTrajectory> {
  public:
    virtual ~quadrotor_msgs_msg_LQRTrajectory_common(){}
    virtual void copy_from_struct(quadrotor_msgs::LQRTrajectory* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const quadrotor_msgs::LQRTrajectory* msg, MultiLibLoader loader, size_t size = 1);
};
  void quadrotor_msgs_msg_LQRTrajectory_common::copy_from_struct(quadrotor_msgs::LQRTrajectory* msg, const matlab::data::Struct& arr,
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
        //trajectory_id
        const matlab::data::TypedArray<uint32_t> trajectory_id_arr = arr["TrajectoryId"];
        msg->trajectory_id = trajectory_id_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'TrajectoryId' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'TrajectoryId' is wrong type; expected a uint32.");
    }
    try {
        //action
        const matlab::data::TypedArray<uint32_t> action_arr = arr["Action"];
        msg->action = action_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Action' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Action' is wrong type; expected a uint32.");
    }
    try {
        //r
        const matlab::data::TypedArray<double> r_arr = arr["R"];
        msg->r = r_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'R' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'R' is wrong type; expected a double.");
    }
    try {
        //start_yaw
        const matlab::data::TypedArray<double> start_yaw_arr = arr["StartYaw"];
        msg->start_yaw = start_yaw_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'StartYaw' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'StartYaw' is wrong type; expected a double.");
    }
    try {
        //final_yaw
        const matlab::data::TypedArray<double> final_yaw_arr = arr["FinalYaw"];
        msg->final_yaw = final_yaw_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'FinalYaw' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'FinalYaw' is wrong type; expected a double.");
    }
    try {
        //s0
        const matlab::data::TypedArray<double> s0_arr = arr["S0"];
        size_t nelem = 6;
        	std::copy(s0_arr.begin(), s0_arr.begin()+nelem, msg->s0.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'S0' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'S0' is wrong type; expected a double.");
    }
    try {
        //ut
        const matlab::data::TypedArray<double> ut_arr = arr["Ut"];
        size_t nelem = 3;
        	std::copy(ut_arr.begin(), ut_arr.begin()+nelem, msg->ut.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Ut' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Ut' is wrong type; expected a double.");
    }
    try {
        //sf
        const matlab::data::TypedArray<double> sf_arr = arr["Sf"];
        size_t nelem = 6;
        	std::copy(sf_arr.begin(), sf_arr.begin()+nelem, msg->sf.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Sf' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Sf' is wrong type; expected a double.");
    }
    try {
        //t_f
        const matlab::data::TypedArray<double> t_f_arr = arr["TF"];
        msg->t_f = t_f_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'TF' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'TF' is wrong type; expected a double.");
    }
    try {
        //debug_info
        const matlab::data::CharArray debug_info_arr = arr["DebugInfo"];
        msg->debug_info = debug_info_arr.toAscii();
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'DebugInfo' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'DebugInfo' is wrong type; expected a char.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T quadrotor_msgs_msg_LQRTrajectory_common::get_arr(MDFactory_T& factory, const quadrotor_msgs::LQRTrajectory* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Header","TrajectoryId","ACTIONADD","ACTIONABORT","ACTIONWARNSTART","ACTIONWARNFINAL","ACTIONWARNIMPOSSIBLE","Action","R","StartYaw","FinalYaw","S0","Ut","Sf","TF","DebugInfo"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("quadrotor_msgs/LQRTrajectory");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::Header>("std_msgs_msg_Header_common",loader);
    outArray[ctr]["Header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // trajectory_id
    auto currentElement_trajectory_id = (msg + ctr)->trajectory_id;
    outArray[ctr]["TrajectoryId"] = factory.createScalar(currentElement_trajectory_id);
    // ACTION_ADD
    auto currentElement_ACTION_ADD = (msg + ctr)->ACTION_ADD;
    outArray[ctr]["ACTIONADD"] = factory.createScalar(static_cast<uint32_t>(currentElement_ACTION_ADD));
    // ACTION_ABORT
    auto currentElement_ACTION_ABORT = (msg + ctr)->ACTION_ABORT;
    outArray[ctr]["ACTIONABORT"] = factory.createScalar(static_cast<uint32_t>(currentElement_ACTION_ABORT));
    // ACTION_WARN_START
    auto currentElement_ACTION_WARN_START = (msg + ctr)->ACTION_WARN_START;
    outArray[ctr]["ACTIONWARNSTART"] = factory.createScalar(static_cast<uint32_t>(currentElement_ACTION_WARN_START));
    // ACTION_WARN_FINAL
    auto currentElement_ACTION_WARN_FINAL = (msg + ctr)->ACTION_WARN_FINAL;
    outArray[ctr]["ACTIONWARNFINAL"] = factory.createScalar(static_cast<uint32_t>(currentElement_ACTION_WARN_FINAL));
    // ACTION_WARN_IMPOSSIBLE
    auto currentElement_ACTION_WARN_IMPOSSIBLE = (msg + ctr)->ACTION_WARN_IMPOSSIBLE;
    outArray[ctr]["ACTIONWARNIMPOSSIBLE"] = factory.createScalar(static_cast<uint32_t>(currentElement_ACTION_WARN_IMPOSSIBLE));
    // action
    auto currentElement_action = (msg + ctr)->action;
    outArray[ctr]["Action"] = factory.createScalar(currentElement_action);
    // r
    auto currentElement_r = (msg + ctr)->r;
    outArray[ctr]["R"] = factory.createScalar(currentElement_r);
    // start_yaw
    auto currentElement_start_yaw = (msg + ctr)->start_yaw;
    outArray[ctr]["StartYaw"] = factory.createScalar(currentElement_start_yaw);
    // final_yaw
    auto currentElement_final_yaw = (msg + ctr)->final_yaw;
    outArray[ctr]["FinalYaw"] = factory.createScalar(currentElement_final_yaw);
    // s0
    auto currentElement_s0 = (msg + ctr)->s0;
    outArray[ctr]["S0"] = factory.createArray<quadrotor_msgs::LQRTrajectory::_s0_type::const_iterator, double>({currentElement_s0.size(),1}, currentElement_s0.begin(), currentElement_s0.end());
    // ut
    auto currentElement_ut = (msg + ctr)->ut;
    outArray[ctr]["Ut"] = factory.createArray<quadrotor_msgs::LQRTrajectory::_ut_type::const_iterator, double>({currentElement_ut.size(),1}, currentElement_ut.begin(), currentElement_ut.end());
    // sf
    auto currentElement_sf = (msg + ctr)->sf;
    outArray[ctr]["Sf"] = factory.createArray<quadrotor_msgs::LQRTrajectory::_sf_type::const_iterator, double>({currentElement_sf.size(),1}, currentElement_sf.begin(), currentElement_sf.end());
    // t_f
    auto currentElement_t_f = (msg + ctr)->t_f;
    outArray[ctr]["TF"] = factory.createScalar(currentElement_t_f);
    // debug_info
    auto currentElement_debug_info = (msg + ctr)->debug_info;
    outArray[ctr]["DebugInfo"] = factory.createCharArray(currentElement_debug_info);
    }
    return std::move(outArray);
  } 
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_LQRTrajectory_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~quadrotor_msgs_LQRTrajectory_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          quadrotor_msgs_LQRTrajectory_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<quadrotor_msgs::LQRTrajectory,quadrotor_msgs_msg_LQRTrajectory_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         quadrotor_msgs_LQRTrajectory_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<quadrotor_msgs::LQRTrajectory,quadrotor_msgs::LQRTrajectory::ConstPtr,quadrotor_msgs_msg_LQRTrajectory_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         quadrotor_msgs_LQRTrajectory_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<quadrotor_msgs::LQRTrajectory,quadrotor_msgs_msg_LQRTrajectory_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_msg_LQRTrajectory_common, MATLABROSMsgInterface<quadrotor_msgs::LQRTrajectory>)
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_LQRTrajectory_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1
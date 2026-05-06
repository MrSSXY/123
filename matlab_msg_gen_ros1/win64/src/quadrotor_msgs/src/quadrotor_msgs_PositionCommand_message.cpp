// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for quadrotor_msgs/PositionCommand
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
#include "quadrotor_msgs/PositionCommand.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_msg_PositionCommand_common : public MATLABROSMsgInterface<quadrotor_msgs::PositionCommand> {
  public:
    virtual ~quadrotor_msgs_msg_PositionCommand_common(){}
    virtual void copy_from_struct(quadrotor_msgs::PositionCommand* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const quadrotor_msgs::PositionCommand* msg, MultiLibLoader loader, size_t size = 1);
};
  void quadrotor_msgs_msg_PositionCommand_common::copy_from_struct(quadrotor_msgs::PositionCommand* msg, const matlab::data::Struct& arr,
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
        //position
        const matlab::data::StructArray position_arr = arr["Position"];
        auto msgClassPtr_position = getCommonObject<geometry_msgs::Point>("geometry_msgs_msg_Point_common",loader);
        msgClassPtr_position->copy_from_struct(&msg->position,position_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Position' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Position' is wrong type; expected a struct.");
    }
    try {
        //velocity
        const matlab::data::StructArray velocity_arr = arr["Velocity"];
        auto msgClassPtr_velocity = getCommonObject<geometry_msgs::Vector3>("geometry_msgs_msg_Vector3_common",loader);
        msgClassPtr_velocity->copy_from_struct(&msg->velocity,velocity_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Velocity' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Velocity' is wrong type; expected a struct.");
    }
    try {
        //acceleration
        const matlab::data::StructArray acceleration_arr = arr["Acceleration"];
        auto msgClassPtr_acceleration = getCommonObject<geometry_msgs::Vector3>("geometry_msgs_msg_Vector3_common",loader);
        msgClassPtr_acceleration->copy_from_struct(&msg->acceleration,acceleration_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Acceleration' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Acceleration' is wrong type; expected a struct.");
    }
    try {
        //yaw
        const matlab::data::TypedArray<double> yaw_arr = arr["Yaw"];
        msg->yaw = yaw_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Yaw' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Yaw' is wrong type; expected a double.");
    }
    try {
        //yaw_dot
        const matlab::data::TypedArray<double> yaw_dot_arr = arr["YawDot"];
        msg->yaw_dot = yaw_dot_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'YawDot' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'YawDot' is wrong type; expected a double.");
    }
    try {
        //kx
        const matlab::data::TypedArray<double> kx_arr = arr["Kx"];
        size_t nelem = 3;
        	std::copy(kx_arr.begin(), kx_arr.begin()+nelem, msg->kx.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Kx' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Kx' is wrong type; expected a double.");
    }
    try {
        //kv
        const matlab::data::TypedArray<double> kv_arr = arr["Kv"];
        size_t nelem = 3;
        	std::copy(kv_arr.begin(), kv_arr.begin()+nelem, msg->kv.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Kv' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Kv' is wrong type; expected a double.");
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
        //trajectory_flag
        const matlab::data::TypedArray<uint8_t> trajectory_flag_arr = arr["TrajectoryFlag"];
        msg->trajectory_flag = trajectory_flag_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'TrajectoryFlag' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'TrajectoryFlag' is wrong type; expected a uint8.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T quadrotor_msgs_msg_PositionCommand_common::get_arr(MDFactory_T& factory, const quadrotor_msgs::PositionCommand* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Header","Position","Velocity","Acceleration","Yaw","YawDot","Kx","Kv","TrajectoryId","TRAJECTORYSTATUSEMPTY","TRAJECTORYSTATUSREADY","TRAJECTORYSTATUSCOMPLETED","TRAJECTROYSTATUSABORT","TRAJECTORYSTATUSILLEGALSTART","TRAJECTORYSTATUSILLEGALFINAL","TRAJECTORYSTATUSIMPOSSIBLE","TrajectoryFlag"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("quadrotor_msgs/PositionCommand");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::Header>("std_msgs_msg_Header_common",loader);
    outArray[ctr]["Header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // position
    auto currentElement_position = (msg + ctr)->position;
    auto msgClassPtr_position = getCommonObject<geometry_msgs::Point>("geometry_msgs_msg_Point_common",loader);
    outArray[ctr]["Position"] = msgClassPtr_position->get_arr(factory, &currentElement_position, loader);
    // velocity
    auto currentElement_velocity = (msg + ctr)->velocity;
    auto msgClassPtr_velocity = getCommonObject<geometry_msgs::Vector3>("geometry_msgs_msg_Vector3_common",loader);
    outArray[ctr]["Velocity"] = msgClassPtr_velocity->get_arr(factory, &currentElement_velocity, loader);
    // acceleration
    auto currentElement_acceleration = (msg + ctr)->acceleration;
    auto msgClassPtr_acceleration = getCommonObject<geometry_msgs::Vector3>("geometry_msgs_msg_Vector3_common",loader);
    outArray[ctr]["Acceleration"] = msgClassPtr_acceleration->get_arr(factory, &currentElement_acceleration, loader);
    // yaw
    auto currentElement_yaw = (msg + ctr)->yaw;
    outArray[ctr]["Yaw"] = factory.createScalar(currentElement_yaw);
    // yaw_dot
    auto currentElement_yaw_dot = (msg + ctr)->yaw_dot;
    outArray[ctr]["YawDot"] = factory.createScalar(currentElement_yaw_dot);
    // kx
    auto currentElement_kx = (msg + ctr)->kx;
    outArray[ctr]["Kx"] = factory.createArray<quadrotor_msgs::PositionCommand::_kx_type::const_iterator, double>({currentElement_kx.size(),1}, currentElement_kx.begin(), currentElement_kx.end());
    // kv
    auto currentElement_kv = (msg + ctr)->kv;
    outArray[ctr]["Kv"] = factory.createArray<quadrotor_msgs::PositionCommand::_kv_type::const_iterator, double>({currentElement_kv.size(),1}, currentElement_kv.begin(), currentElement_kv.end());
    // trajectory_id
    auto currentElement_trajectory_id = (msg + ctr)->trajectory_id;
    outArray[ctr]["TrajectoryId"] = factory.createScalar(currentElement_trajectory_id);
    // TRAJECTORY_STATUS_EMPTY
    auto currentElement_TRAJECTORY_STATUS_EMPTY = (msg + ctr)->TRAJECTORY_STATUS_EMPTY;
    outArray[ctr]["TRAJECTORYSTATUSEMPTY"] = factory.createScalar(static_cast<uint8_t>(currentElement_TRAJECTORY_STATUS_EMPTY));
    // TRAJECTORY_STATUS_READY
    auto currentElement_TRAJECTORY_STATUS_READY = (msg + ctr)->TRAJECTORY_STATUS_READY;
    outArray[ctr]["TRAJECTORYSTATUSREADY"] = factory.createScalar(static_cast<uint8_t>(currentElement_TRAJECTORY_STATUS_READY));
    // TRAJECTORY_STATUS_COMPLETED
    auto currentElement_TRAJECTORY_STATUS_COMPLETED = (msg + ctr)->TRAJECTORY_STATUS_COMPLETED;
    outArray[ctr]["TRAJECTORYSTATUSCOMPLETED"] = factory.createScalar(static_cast<uint8_t>(currentElement_TRAJECTORY_STATUS_COMPLETED));
    // TRAJECTROY_STATUS_ABORT
    auto currentElement_TRAJECTROY_STATUS_ABORT = (msg + ctr)->TRAJECTROY_STATUS_ABORT;
    outArray[ctr]["TRAJECTROYSTATUSABORT"] = factory.createScalar(static_cast<uint8_t>(currentElement_TRAJECTROY_STATUS_ABORT));
    // TRAJECTORY_STATUS_ILLEGAL_START
    auto currentElement_TRAJECTORY_STATUS_ILLEGAL_START = (msg + ctr)->TRAJECTORY_STATUS_ILLEGAL_START;
    outArray[ctr]["TRAJECTORYSTATUSILLEGALSTART"] = factory.createScalar(static_cast<uint8_t>(currentElement_TRAJECTORY_STATUS_ILLEGAL_START));
    // TRAJECTORY_STATUS_ILLEGAL_FINAL
    auto currentElement_TRAJECTORY_STATUS_ILLEGAL_FINAL = (msg + ctr)->TRAJECTORY_STATUS_ILLEGAL_FINAL;
    outArray[ctr]["TRAJECTORYSTATUSILLEGALFINAL"] = factory.createScalar(static_cast<uint8_t>(currentElement_TRAJECTORY_STATUS_ILLEGAL_FINAL));
    // TRAJECTORY_STATUS_IMPOSSIBLE
    auto currentElement_TRAJECTORY_STATUS_IMPOSSIBLE = (msg + ctr)->TRAJECTORY_STATUS_IMPOSSIBLE;
    outArray[ctr]["TRAJECTORYSTATUSIMPOSSIBLE"] = factory.createScalar(static_cast<uint8_t>(currentElement_TRAJECTORY_STATUS_IMPOSSIBLE));
    // trajectory_flag
    auto currentElement_trajectory_flag = (msg + ctr)->trajectory_flag;
    outArray[ctr]["TrajectoryFlag"] = factory.createScalar(currentElement_trajectory_flag);
    }
    return std::move(outArray);
  } 
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_PositionCommand_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~quadrotor_msgs_PositionCommand_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          quadrotor_msgs_PositionCommand_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<quadrotor_msgs::PositionCommand,quadrotor_msgs_msg_PositionCommand_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         quadrotor_msgs_PositionCommand_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<quadrotor_msgs::PositionCommand,quadrotor_msgs::PositionCommand::ConstPtr,quadrotor_msgs_msg_PositionCommand_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         quadrotor_msgs_PositionCommand_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<quadrotor_msgs::PositionCommand,quadrotor_msgs_msg_PositionCommand_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_msg_PositionCommand_common, MATLABROSMsgInterface<quadrotor_msgs::PositionCommand>)
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_PositionCommand_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1
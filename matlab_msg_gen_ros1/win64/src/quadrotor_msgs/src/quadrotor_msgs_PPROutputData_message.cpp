// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for quadrotor_msgs/PPROutputData
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
#include "quadrotor_msgs/PPROutputData.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_msg_PPROutputData_common : public MATLABROSMsgInterface<quadrotor_msgs::PPROutputData> {
  public:
    virtual ~quadrotor_msgs_msg_PPROutputData_common(){}
    virtual void copy_from_struct(quadrotor_msgs::PPROutputData* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const quadrotor_msgs::PPROutputData* msg, MultiLibLoader loader, size_t size = 1);
};
  void quadrotor_msgs_msg_PPROutputData_common::copy_from_struct(quadrotor_msgs::PPROutputData* msg, const matlab::data::Struct& arr,
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
        //quad_time
        const matlab::data::TypedArray<uint16_t> quad_time_arr = arr["QuadTime"];
        msg->quad_time = quad_time_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'QuadTime' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'QuadTime' is wrong type; expected a uint16.");
    }
    try {
        //des_thrust
        const matlab::data::TypedArray<double> des_thrust_arr = arr["DesThrust"];
        msg->des_thrust = des_thrust_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'DesThrust' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'DesThrust' is wrong type; expected a double.");
    }
    try {
        //des_roll
        const matlab::data::TypedArray<double> des_roll_arr = arr["DesRoll"];
        msg->des_roll = des_roll_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'DesRoll' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'DesRoll' is wrong type; expected a double.");
    }
    try {
        //des_pitch
        const matlab::data::TypedArray<double> des_pitch_arr = arr["DesPitch"];
        msg->des_pitch = des_pitch_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'DesPitch' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'DesPitch' is wrong type; expected a double.");
    }
    try {
        //des_yaw
        const matlab::data::TypedArray<double> des_yaw_arr = arr["DesYaw"];
        msg->des_yaw = des_yaw_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'DesYaw' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'DesYaw' is wrong type; expected a double.");
    }
    try {
        //est_roll
        const matlab::data::TypedArray<double> est_roll_arr = arr["EstRoll"];
        msg->est_roll = est_roll_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'EstRoll' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'EstRoll' is wrong type; expected a double.");
    }
    try {
        //est_pitch
        const matlab::data::TypedArray<double> est_pitch_arr = arr["EstPitch"];
        msg->est_pitch = est_pitch_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'EstPitch' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'EstPitch' is wrong type; expected a double.");
    }
    try {
        //est_yaw
        const matlab::data::TypedArray<double> est_yaw_arr = arr["EstYaw"];
        msg->est_yaw = est_yaw_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'EstYaw' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'EstYaw' is wrong type; expected a double.");
    }
    try {
        //est_angvel_x
        const matlab::data::TypedArray<double> est_angvel_x_arr = arr["EstAngvelX"];
        msg->est_angvel_x = est_angvel_x_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'EstAngvelX' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'EstAngvelX' is wrong type; expected a double.");
    }
    try {
        //est_angvel_y
        const matlab::data::TypedArray<double> est_angvel_y_arr = arr["EstAngvelY"];
        msg->est_angvel_y = est_angvel_y_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'EstAngvelY' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'EstAngvelY' is wrong type; expected a double.");
    }
    try {
        //est_angvel_z
        const matlab::data::TypedArray<double> est_angvel_z_arr = arr["EstAngvelZ"];
        msg->est_angvel_z = est_angvel_z_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'EstAngvelZ' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'EstAngvelZ' is wrong type; expected a double.");
    }
    try {
        //est_acc_x
        const matlab::data::TypedArray<double> est_acc_x_arr = arr["EstAccX"];
        msg->est_acc_x = est_acc_x_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'EstAccX' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'EstAccX' is wrong type; expected a double.");
    }
    try {
        //est_acc_y
        const matlab::data::TypedArray<double> est_acc_y_arr = arr["EstAccY"];
        msg->est_acc_y = est_acc_y_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'EstAccY' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'EstAccY' is wrong type; expected a double.");
    }
    try {
        //est_acc_z
        const matlab::data::TypedArray<double> est_acc_z_arr = arr["EstAccZ"];
        msg->est_acc_z = est_acc_z_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'EstAccZ' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'EstAccZ' is wrong type; expected a double.");
    }
    try {
        //pwm
        const matlab::data::TypedArray<uint16_t> pwm_arr = arr["Pwm"];
        size_t nelem = 4;
        	std::copy(pwm_arr.begin(), pwm_arr.begin()+nelem, msg->pwm.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Pwm' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Pwm' is wrong type; expected a uint16.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T quadrotor_msgs_msg_PPROutputData_common::get_arr(MDFactory_T& factory, const quadrotor_msgs::PPROutputData* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Header","QuadTime","DesThrust","DesRoll","DesPitch","DesYaw","EstRoll","EstPitch","EstYaw","EstAngvelX","EstAngvelY","EstAngvelZ","EstAccX","EstAccY","EstAccZ","Pwm"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("quadrotor_msgs/PPROutputData");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::Header>("std_msgs_msg_Header_common",loader);
    outArray[ctr]["Header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // quad_time
    auto currentElement_quad_time = (msg + ctr)->quad_time;
    outArray[ctr]["QuadTime"] = factory.createScalar(currentElement_quad_time);
    // des_thrust
    auto currentElement_des_thrust = (msg + ctr)->des_thrust;
    outArray[ctr]["DesThrust"] = factory.createScalar(currentElement_des_thrust);
    // des_roll
    auto currentElement_des_roll = (msg + ctr)->des_roll;
    outArray[ctr]["DesRoll"] = factory.createScalar(currentElement_des_roll);
    // des_pitch
    auto currentElement_des_pitch = (msg + ctr)->des_pitch;
    outArray[ctr]["DesPitch"] = factory.createScalar(currentElement_des_pitch);
    // des_yaw
    auto currentElement_des_yaw = (msg + ctr)->des_yaw;
    outArray[ctr]["DesYaw"] = factory.createScalar(currentElement_des_yaw);
    // est_roll
    auto currentElement_est_roll = (msg + ctr)->est_roll;
    outArray[ctr]["EstRoll"] = factory.createScalar(currentElement_est_roll);
    // est_pitch
    auto currentElement_est_pitch = (msg + ctr)->est_pitch;
    outArray[ctr]["EstPitch"] = factory.createScalar(currentElement_est_pitch);
    // est_yaw
    auto currentElement_est_yaw = (msg + ctr)->est_yaw;
    outArray[ctr]["EstYaw"] = factory.createScalar(currentElement_est_yaw);
    // est_angvel_x
    auto currentElement_est_angvel_x = (msg + ctr)->est_angvel_x;
    outArray[ctr]["EstAngvelX"] = factory.createScalar(currentElement_est_angvel_x);
    // est_angvel_y
    auto currentElement_est_angvel_y = (msg + ctr)->est_angvel_y;
    outArray[ctr]["EstAngvelY"] = factory.createScalar(currentElement_est_angvel_y);
    // est_angvel_z
    auto currentElement_est_angvel_z = (msg + ctr)->est_angvel_z;
    outArray[ctr]["EstAngvelZ"] = factory.createScalar(currentElement_est_angvel_z);
    // est_acc_x
    auto currentElement_est_acc_x = (msg + ctr)->est_acc_x;
    outArray[ctr]["EstAccX"] = factory.createScalar(currentElement_est_acc_x);
    // est_acc_y
    auto currentElement_est_acc_y = (msg + ctr)->est_acc_y;
    outArray[ctr]["EstAccY"] = factory.createScalar(currentElement_est_acc_y);
    // est_acc_z
    auto currentElement_est_acc_z = (msg + ctr)->est_acc_z;
    outArray[ctr]["EstAccZ"] = factory.createScalar(currentElement_est_acc_z);
    // pwm
    auto currentElement_pwm = (msg + ctr)->pwm;
    outArray[ctr]["Pwm"] = factory.createArray<quadrotor_msgs::PPROutputData::_pwm_type::const_iterator, uint16_t>({currentElement_pwm.size(),1}, currentElement_pwm.begin(), currentElement_pwm.end());
    }
    return std::move(outArray);
  } 
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_PPROutputData_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~quadrotor_msgs_PPROutputData_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          quadrotor_msgs_PPROutputData_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<quadrotor_msgs::PPROutputData,quadrotor_msgs_msg_PPROutputData_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         quadrotor_msgs_PPROutputData_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<quadrotor_msgs::PPROutputData,quadrotor_msgs::PPROutputData::ConstPtr,quadrotor_msgs_msg_PPROutputData_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         quadrotor_msgs_PPROutputData_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<quadrotor_msgs::PPROutputData,quadrotor_msgs_msg_PPROutputData_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_msg_PPROutputData_common, MATLABROSMsgInterface<quadrotor_msgs::PPROutputData>)
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_PPROutputData_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1
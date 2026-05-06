// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for quadrotor_msgs/OutputData
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
#include "quadrotor_msgs/OutputData.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_msg_OutputData_common : public MATLABROSMsgInterface<quadrotor_msgs::OutputData> {
  public:
    virtual ~quadrotor_msgs_msg_OutputData_common(){}
    virtual void copy_from_struct(quadrotor_msgs::OutputData* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const quadrotor_msgs::OutputData* msg, MultiLibLoader loader, size_t size = 1);
};
  void quadrotor_msgs_msg_OutputData_common::copy_from_struct(quadrotor_msgs::OutputData* msg, const matlab::data::Struct& arr,
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
        //loop_rate
        const matlab::data::TypedArray<uint16_t> loop_rate_arr = arr["LoopRate"];
        msg->loop_rate = loop_rate_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'LoopRate' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'LoopRate' is wrong type; expected a uint16.");
    }
    try {
        //voltage
        const matlab::data::TypedArray<double> voltage_arr = arr["Voltage"];
        msg->voltage = voltage_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Voltage' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Voltage' is wrong type; expected a double.");
    }
    try {
        //orientation
        const matlab::data::StructArray orientation_arr = arr["Orientation"];
        auto msgClassPtr_orientation = getCommonObject<geometry_msgs::Quaternion>("geometry_msgs_msg_Quaternion_common",loader);
        msgClassPtr_orientation->copy_from_struct(&msg->orientation,orientation_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Orientation' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Orientation' is wrong type; expected a struct.");
    }
    try {
        //angular_velocity
        const matlab::data::StructArray angular_velocity_arr = arr["AngularVelocity"];
        auto msgClassPtr_angular_velocity = getCommonObject<geometry_msgs::Vector3>("geometry_msgs_msg_Vector3_common",loader);
        msgClassPtr_angular_velocity->copy_from_struct(&msg->angular_velocity,angular_velocity_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'AngularVelocity' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'AngularVelocity' is wrong type; expected a struct.");
    }
    try {
        //linear_acceleration
        const matlab::data::StructArray linear_acceleration_arr = arr["LinearAcceleration"];
        auto msgClassPtr_linear_acceleration = getCommonObject<geometry_msgs::Vector3>("geometry_msgs_msg_Vector3_common",loader);
        msgClassPtr_linear_acceleration->copy_from_struct(&msg->linear_acceleration,linear_acceleration_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'LinearAcceleration' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'LinearAcceleration' is wrong type; expected a struct.");
    }
    try {
        //pressure_dheight
        const matlab::data::TypedArray<double> pressure_dheight_arr = arr["PressureDheight"];
        msg->pressure_dheight = pressure_dheight_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'PressureDheight' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'PressureDheight' is wrong type; expected a double.");
    }
    try {
        //pressure_height
        const matlab::data::TypedArray<double> pressure_height_arr = arr["PressureHeight"];
        msg->pressure_height = pressure_height_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'PressureHeight' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'PressureHeight' is wrong type; expected a double.");
    }
    try {
        //magnetic_field
        const matlab::data::StructArray magnetic_field_arr = arr["MagneticField"];
        auto msgClassPtr_magnetic_field = getCommonObject<geometry_msgs::Vector3>("geometry_msgs_msg_Vector3_common",loader);
        msgClassPtr_magnetic_field->copy_from_struct(&msg->magnetic_field,magnetic_field_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'MagneticField' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'MagneticField' is wrong type; expected a struct.");
    }
    try {
        //radio_channel
        const matlab::data::TypedArray<uint8_t> radio_channel_arr = arr["RadioChannel"];
        size_t nelem = 8;
        	std::copy(radio_channel_arr.begin(), radio_channel_arr.begin()+nelem, msg->radio_channel.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'RadioChannel' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'RadioChannel' is wrong type; expected a uint8.");
    }
    try {
        //seq
        const matlab::data::TypedArray<uint8_t> seq_arr = arr["Seq"];
        msg->seq = seq_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Seq' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Seq' is wrong type; expected a uint8.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T quadrotor_msgs_msg_OutputData_common::get_arr(MDFactory_T& factory, const quadrotor_msgs::OutputData* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Header","LoopRate","Voltage","Orientation","AngularVelocity","LinearAcceleration","PressureDheight","PressureHeight","MagneticField","RadioChannel","Seq"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("quadrotor_msgs/OutputData");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::Header>("std_msgs_msg_Header_common",loader);
    outArray[ctr]["Header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // loop_rate
    auto currentElement_loop_rate = (msg + ctr)->loop_rate;
    outArray[ctr]["LoopRate"] = factory.createScalar(currentElement_loop_rate);
    // voltage
    auto currentElement_voltage = (msg + ctr)->voltage;
    outArray[ctr]["Voltage"] = factory.createScalar(currentElement_voltage);
    // orientation
    auto currentElement_orientation = (msg + ctr)->orientation;
    auto msgClassPtr_orientation = getCommonObject<geometry_msgs::Quaternion>("geometry_msgs_msg_Quaternion_common",loader);
    outArray[ctr]["Orientation"] = msgClassPtr_orientation->get_arr(factory, &currentElement_orientation, loader);
    // angular_velocity
    auto currentElement_angular_velocity = (msg + ctr)->angular_velocity;
    auto msgClassPtr_angular_velocity = getCommonObject<geometry_msgs::Vector3>("geometry_msgs_msg_Vector3_common",loader);
    outArray[ctr]["AngularVelocity"] = msgClassPtr_angular_velocity->get_arr(factory, &currentElement_angular_velocity, loader);
    // linear_acceleration
    auto currentElement_linear_acceleration = (msg + ctr)->linear_acceleration;
    auto msgClassPtr_linear_acceleration = getCommonObject<geometry_msgs::Vector3>("geometry_msgs_msg_Vector3_common",loader);
    outArray[ctr]["LinearAcceleration"] = msgClassPtr_linear_acceleration->get_arr(factory, &currentElement_linear_acceleration, loader);
    // pressure_dheight
    auto currentElement_pressure_dheight = (msg + ctr)->pressure_dheight;
    outArray[ctr]["PressureDheight"] = factory.createScalar(currentElement_pressure_dheight);
    // pressure_height
    auto currentElement_pressure_height = (msg + ctr)->pressure_height;
    outArray[ctr]["PressureHeight"] = factory.createScalar(currentElement_pressure_height);
    // magnetic_field
    auto currentElement_magnetic_field = (msg + ctr)->magnetic_field;
    auto msgClassPtr_magnetic_field = getCommonObject<geometry_msgs::Vector3>("geometry_msgs_msg_Vector3_common",loader);
    outArray[ctr]["MagneticField"] = msgClassPtr_magnetic_field->get_arr(factory, &currentElement_magnetic_field, loader);
    // radio_channel
    auto currentElement_radio_channel = (msg + ctr)->radio_channel;
    outArray[ctr]["RadioChannel"] = factory.createArray<quadrotor_msgs::OutputData::_radio_channel_type::const_iterator, uint8_t>({currentElement_radio_channel.size(),1}, currentElement_radio_channel.begin(), currentElement_radio_channel.end());
    // seq
    auto currentElement_seq = (msg + ctr)->seq;
    outArray[ctr]["Seq"] = factory.createScalar(currentElement_seq);
    }
    return std::move(outArray);
  } 
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_OutputData_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~quadrotor_msgs_OutputData_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          quadrotor_msgs_OutputData_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<quadrotor_msgs::OutputData,quadrotor_msgs_msg_OutputData_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         quadrotor_msgs_OutputData_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<quadrotor_msgs::OutputData,quadrotor_msgs::OutputData::ConstPtr,quadrotor_msgs_msg_OutputData_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         quadrotor_msgs_OutputData_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<quadrotor_msgs::OutputData,quadrotor_msgs_msg_OutputData_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_msg_OutputData_common, MATLABROSMsgInterface<quadrotor_msgs::OutputData>)
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_OutputData_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1
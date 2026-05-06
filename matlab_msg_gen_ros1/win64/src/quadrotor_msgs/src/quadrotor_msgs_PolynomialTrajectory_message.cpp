// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for quadrotor_msgs/PolynomialTrajectory
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
#include "quadrotor_msgs/PolynomialTrajectory.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_msg_PolynomialTrajectory_common : public MATLABROSMsgInterface<quadrotor_msgs::PolynomialTrajectory> {
  public:
    virtual ~quadrotor_msgs_msg_PolynomialTrajectory_common(){}
    virtual void copy_from_struct(quadrotor_msgs::PolynomialTrajectory* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const quadrotor_msgs::PolynomialTrajectory* msg, MultiLibLoader loader, size_t size = 1);
};
  void quadrotor_msgs_msg_PolynomialTrajectory_common::copy_from_struct(quadrotor_msgs::PolynomialTrajectory* msg, const matlab::data::Struct& arr,
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
        //num_order
        const matlab::data::TypedArray<uint32_t> num_order_arr = arr["NumOrder"];
        msg->num_order = num_order_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'NumOrder' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'NumOrder' is wrong type; expected a uint32.");
    }
    try {
        //num_segment
        const matlab::data::TypedArray<uint32_t> num_segment_arr = arr["NumSegment"];
        msg->num_segment = num_segment_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'NumSegment' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'NumSegment' is wrong type; expected a uint32.");
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
        //coef_x
        const matlab::data::TypedArray<double> coef_x_arr = arr["CoefX"];
        size_t nelem = coef_x_arr.getNumberOfElements();
        	msg->coef_x.resize(nelem);
        	std::copy(coef_x_arr.begin(), coef_x_arr.begin()+nelem, msg->coef_x.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'CoefX' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'CoefX' is wrong type; expected a double.");
    }
    try {
        //coef_y
        const matlab::data::TypedArray<double> coef_y_arr = arr["CoefY"];
        size_t nelem = coef_y_arr.getNumberOfElements();
        	msg->coef_y.resize(nelem);
        	std::copy(coef_y_arr.begin(), coef_y_arr.begin()+nelem, msg->coef_y.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'CoefY' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'CoefY' is wrong type; expected a double.");
    }
    try {
        //coef_z
        const matlab::data::TypedArray<double> coef_z_arr = arr["CoefZ"];
        size_t nelem = coef_z_arr.getNumberOfElements();
        	msg->coef_z.resize(nelem);
        	std::copy(coef_z_arr.begin(), coef_z_arr.begin()+nelem, msg->coef_z.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'CoefZ' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'CoefZ' is wrong type; expected a double.");
    }
    try {
        //time
        const matlab::data::TypedArray<double> time_arr = arr["Time"];
        size_t nelem = time_arr.getNumberOfElements();
        	msg->time.resize(nelem);
        	std::copy(time_arr.begin(), time_arr.begin()+nelem, msg->time.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Time' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Time' is wrong type; expected a double.");
    }
    try {
        //mag_coeff
        const matlab::data::TypedArray<double> mag_coeff_arr = arr["MagCoeff"];
        msg->mag_coeff = mag_coeff_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'MagCoeff' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'MagCoeff' is wrong type; expected a double.");
    }
    try {
        //order
        const matlab::data::TypedArray<uint32_t> order_arr = arr["Order"];
        size_t nelem = order_arr.getNumberOfElements();
        	msg->order.resize(nelem);
        	std::copy(order_arr.begin(), order_arr.begin()+nelem, msg->order.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Order' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Order' is wrong type; expected a uint32.");
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
  MDArray_T quadrotor_msgs_msg_PolynomialTrajectory_common::get_arr(MDFactory_T& factory, const quadrotor_msgs::PolynomialTrajectory* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Header","TrajectoryId","ACTIONADD","ACTIONABORT","ACTIONWARNSTART","ACTIONWARNFINAL","ACTIONWARNIMPOSSIBLE","Action","NumOrder","NumSegment","StartYaw","FinalYaw","CoefX","CoefY","CoefZ","Time","MagCoeff","Order","DebugInfo"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("quadrotor_msgs/PolynomialTrajectory");
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
    // num_order
    auto currentElement_num_order = (msg + ctr)->num_order;
    outArray[ctr]["NumOrder"] = factory.createScalar(currentElement_num_order);
    // num_segment
    auto currentElement_num_segment = (msg + ctr)->num_segment;
    outArray[ctr]["NumSegment"] = factory.createScalar(currentElement_num_segment);
    // start_yaw
    auto currentElement_start_yaw = (msg + ctr)->start_yaw;
    outArray[ctr]["StartYaw"] = factory.createScalar(currentElement_start_yaw);
    // final_yaw
    auto currentElement_final_yaw = (msg + ctr)->final_yaw;
    outArray[ctr]["FinalYaw"] = factory.createScalar(currentElement_final_yaw);
    // coef_x
    auto currentElement_coef_x = (msg + ctr)->coef_x;
    outArray[ctr]["CoefX"] = factory.createArray<quadrotor_msgs::PolynomialTrajectory::_coef_x_type::const_iterator, double>({currentElement_coef_x.size(),1}, currentElement_coef_x.begin(), currentElement_coef_x.end());
    // coef_y
    auto currentElement_coef_y = (msg + ctr)->coef_y;
    outArray[ctr]["CoefY"] = factory.createArray<quadrotor_msgs::PolynomialTrajectory::_coef_y_type::const_iterator, double>({currentElement_coef_y.size(),1}, currentElement_coef_y.begin(), currentElement_coef_y.end());
    // coef_z
    auto currentElement_coef_z = (msg + ctr)->coef_z;
    outArray[ctr]["CoefZ"] = factory.createArray<quadrotor_msgs::PolynomialTrajectory::_coef_z_type::const_iterator, double>({currentElement_coef_z.size(),1}, currentElement_coef_z.begin(), currentElement_coef_z.end());
    // time
    auto currentElement_time = (msg + ctr)->time;
    outArray[ctr]["Time"] = factory.createArray<quadrotor_msgs::PolynomialTrajectory::_time_type::const_iterator, double>({currentElement_time.size(),1}, currentElement_time.begin(), currentElement_time.end());
    // mag_coeff
    auto currentElement_mag_coeff = (msg + ctr)->mag_coeff;
    outArray[ctr]["MagCoeff"] = factory.createScalar(currentElement_mag_coeff);
    // order
    auto currentElement_order = (msg + ctr)->order;
    outArray[ctr]["Order"] = factory.createArray<quadrotor_msgs::PolynomialTrajectory::_order_type::const_iterator, uint32_t>({currentElement_order.size(),1}, currentElement_order.begin(), currentElement_order.end());
    // debug_info
    auto currentElement_debug_info = (msg + ctr)->debug_info;
    outArray[ctr]["DebugInfo"] = factory.createCharArray(currentElement_debug_info);
    }
    return std::move(outArray);
  } 
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_PolynomialTrajectory_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~quadrotor_msgs_PolynomialTrajectory_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          quadrotor_msgs_PolynomialTrajectory_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<quadrotor_msgs::PolynomialTrajectory,quadrotor_msgs_msg_PolynomialTrajectory_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         quadrotor_msgs_PolynomialTrajectory_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<quadrotor_msgs::PolynomialTrajectory,quadrotor_msgs::PolynomialTrajectory::ConstPtr,quadrotor_msgs_msg_PolynomialTrajectory_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         quadrotor_msgs_PolynomialTrajectory_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<quadrotor_msgs::PolynomialTrajectory,quadrotor_msgs_msg_PolynomialTrajectory_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_msg_PolynomialTrajectory_common, MATLABROSMsgInterface<quadrotor_msgs::PolynomialTrajectory>)
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_PolynomialTrajectory_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1
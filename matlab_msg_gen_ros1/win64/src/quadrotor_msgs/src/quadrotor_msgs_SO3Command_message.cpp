// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for quadrotor_msgs/SO3Command
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
#include "quadrotor_msgs/SO3Command.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_msg_SO3Command_common : public MATLABROSMsgInterface<quadrotor_msgs::SO3Command> {
  public:
    virtual ~quadrotor_msgs_msg_SO3Command_common(){}
    virtual void copy_from_struct(quadrotor_msgs::SO3Command* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const quadrotor_msgs::SO3Command* msg, MultiLibLoader loader, size_t size = 1);
};
  void quadrotor_msgs_msg_SO3Command_common::copy_from_struct(quadrotor_msgs::SO3Command* msg, const matlab::data::Struct& arr,
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
        //force
        const matlab::data::StructArray force_arr = arr["Force"];
        auto msgClassPtr_force = getCommonObject<geometry_msgs::Vector3>("geometry_msgs_msg_Vector3_common",loader);
        msgClassPtr_force->copy_from_struct(&msg->force,force_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Force' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Force' is wrong type; expected a struct.");
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
        //kR
        const matlab::data::TypedArray<double> kR_arr = arr["KR"];
        size_t nelem = 3;
        	std::copy(kR_arr.begin(), kR_arr.begin()+nelem, msg->kR.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'KR' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'KR' is wrong type; expected a double.");
    }
    try {
        //kOm
        const matlab::data::TypedArray<double> kOm_arr = arr["KOm"];
        size_t nelem = 3;
        	std::copy(kOm_arr.begin(), kOm_arr.begin()+nelem, msg->kOm.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'KOm' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'KOm' is wrong type; expected a double.");
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
  MDArray_T quadrotor_msgs_msg_SO3Command_common::get_arr(MDFactory_T& factory, const quadrotor_msgs::SO3Command* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Header","Force","Orientation","KR","KOm","Aux"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("quadrotor_msgs/SO3Command");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::Header>("std_msgs_msg_Header_common",loader);
    outArray[ctr]["Header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // force
    auto currentElement_force = (msg + ctr)->force;
    auto msgClassPtr_force = getCommonObject<geometry_msgs::Vector3>("geometry_msgs_msg_Vector3_common",loader);
    outArray[ctr]["Force"] = msgClassPtr_force->get_arr(factory, &currentElement_force, loader);
    // orientation
    auto currentElement_orientation = (msg + ctr)->orientation;
    auto msgClassPtr_orientation = getCommonObject<geometry_msgs::Quaternion>("geometry_msgs_msg_Quaternion_common",loader);
    outArray[ctr]["Orientation"] = msgClassPtr_orientation->get_arr(factory, &currentElement_orientation, loader);
    // kR
    auto currentElement_kR = (msg + ctr)->kR;
    outArray[ctr]["KR"] = factory.createArray<quadrotor_msgs::SO3Command::_kR_type::const_iterator, double>({currentElement_kR.size(),1}, currentElement_kR.begin(), currentElement_kR.end());
    // kOm
    auto currentElement_kOm = (msg + ctr)->kOm;
    outArray[ctr]["KOm"] = factory.createArray<quadrotor_msgs::SO3Command::_kOm_type::const_iterator, double>({currentElement_kOm.size(),1}, currentElement_kOm.begin(), currentElement_kOm.end());
    // aux
    auto currentElement_aux = (msg + ctr)->aux;
    auto msgClassPtr_aux = getCommonObject<quadrotor_msgs::AuxCommand>("quadrotor_msgs_msg_AuxCommand_common",loader);
    outArray[ctr]["Aux"] = msgClassPtr_aux->get_arr(factory, &currentElement_aux, loader);
    }
    return std::move(outArray);
  } 
class QUADROTOR_MSGS_EXPORT quadrotor_msgs_SO3Command_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~quadrotor_msgs_SO3Command_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          quadrotor_msgs_SO3Command_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<quadrotor_msgs::SO3Command,quadrotor_msgs_msg_SO3Command_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         quadrotor_msgs_SO3Command_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<quadrotor_msgs::SO3Command,quadrotor_msgs::SO3Command::ConstPtr,quadrotor_msgs_msg_SO3Command_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         quadrotor_msgs_SO3Command_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<quadrotor_msgs::SO3Command,quadrotor_msgs_msg_SO3Command_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_msg_SO3Command_common, MATLABROSMsgInterface<quadrotor_msgs::SO3Command>)
CLASS_LOADER_REGISTER_CLASS(quadrotor_msgs_SO3Command_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1
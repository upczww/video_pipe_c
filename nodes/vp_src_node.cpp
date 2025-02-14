
#include <memory>
#include "vp_src_node.h"
#include "../objects/vp_control_meta.h"

namespace vp_nodes {
    
    vp_src_node::vp_src_node(std::string node_name, 
                            int channel_index, 
                            float resize_ratio): 
                            vp_node(node_name), 
                            channel_index(channel_index), 
                            resize_ratio(resize_ratio), 
                            frame_index(-1) {
        assert(resize_ratio > 0 && resize_ratio <= 1.0f);
    }
    
    vp_src_node::~vp_src_node() {

    }
    

    void vp_src_node::handle_run() {
        throw vp_excepts::vp_not_implemented_error("must have re-implementaion for 'handle_run' method in src nodes!");
    }

    std::shared_ptr<vp_objects::vp_meta> 
            vp_src_node::handle_frame_meta(std::shared_ptr<vp_objects::vp_frame_meta> meta) {
        throw vp_excepts::vp_invalid_calling_error("'handle_frame_meta' method could not be called in src nodes!");
    }

    std::shared_ptr<vp_objects::vp_meta> 
            vp_src_node::handle_control_meta(std::shared_ptr<vp_objects::vp_control_meta> meta) {
        throw vp_excepts::vp_invalid_calling_error("'handle_control_meta' method could not be called in src nodes!");
    }

    void vp_src_node::start() {
        this->active = true;
        std::shared_ptr<vp_objects::vp_meta> start_control_meta = std::make_shared<vp_objects::vp_control_meta>(vp_objects::vp_control_type::START, this->channel_index);
        this->push_meta(start_control_meta);
    }

    void vp_src_node::stop() {
        this->active = false;
        std::shared_ptr<vp_objects::vp_meta> stop_control_meta = std::make_shared<vp_objects::vp_control_meta>(vp_objects::vp_control_type::STOP, this->channel_index);
        this->push_meta(stop_control_meta);
    }

    void vp_src_node::refresh() {
        std::shared_ptr<vp_objects::vp_meta> refresh_control_meta = std::make_shared<vp_objects::vp_control_meta>(vp_objects::vp_control_type::REFRESH, this->channel_index);
        this->push_meta(refresh_control_meta);
    }

    void vp_src_node::speak() {
        std::shared_ptr<vp_objects::vp_meta> speak_control_meta = std::make_shared<vp_objects::vp_control_meta>(vp_objects::vp_control_type::SPEAK, this->channel_index);
        this->push_meta(speak_control_meta);
    }

     vp_node_type vp_src_node::node_type() {
         return vp_node_type::SRC;
     }

    int vp_src_node::get_original_fps() const {
        return original_fps;
    }

    int vp_src_node::get_original_width() const {
        return original_width;
    }

    int vp_src_node::get_original_height() const {
        return original_height;
    }
} 

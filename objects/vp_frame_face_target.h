

#pragma once

#include <vector>
#include <memory>

namespace vp_objects {
    // target in frame detected by face detectors such as yunet.
    // note: we can define new target type like vp_frame_xxx_target... if need (see vp_frame_pose_target also)
    class vp_frame_face_target
    {
    private:
        /* data */
    public:
        vp_frame_face_target(int x, 
                            int y, 
                            int width, 
                            int height, 
                            float score, 
                            std::vector<std::pair<int, int>> key_points = std::vector<std::pair<int, int>>(), 
                            std::vector<float> embeddings = std::vector<float>());
        ~vp_frame_face_target();

        // x of top left
        int x;
        // y of top left
        int y;
        // width of rect
        int width;
        // height of rect
        int height;

        // confidence
        float score;

        // feature vector created by infer nodes such as vp_sface_feature_encoder_node.
        // embeddings can be used for face recognize or other reid works.
        std::vector<float> embeddings;

        // key points (5 points or more)
        std::vector<std::pair<int, int>> key_points;

        // clone myself
        std::shared_ptr<vp_frame_face_target> clone();
    };

}
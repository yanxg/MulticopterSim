/*
   MulticopterSim VideoManager class implementation

   Copyright(C) 2019 Simon D.Levy

   MIT License
*/

#include "../MulticopterSim/VideoManager.hpp"

#include <opencv2/highgui/highgui.hpp>

class FExampleVideoManager : public FVideoManager {

    protected:

        virtual void processImage(cv::Mat image) override
        {
            cv::imshow("MulticopterSim", image);
            cv::waitKey(1);
        }

    public:

        FExampleVideoManager(UTextureRenderTarget2D * cameraRenderTarget) :
            FVideoManager(cameraRenderTarget)

        {
        }

        ~FExampleVideoManager()
        {
        }
}; 


// Factory method for VideoManager class
FLIGHTMODULE_API FVideoManager * createVideoManager(UTextureRenderTarget2D * cameraRenderTarget, uint8_t id) 
{
    return new FExampleVideoManager(cameraRenderTarget);
}

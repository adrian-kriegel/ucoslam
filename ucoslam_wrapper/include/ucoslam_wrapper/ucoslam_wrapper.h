
#ifndef _UCOSLAM_WRAPPER_UCOSLAM_WRAPPER_H_
#define _UCOSLAM_WRAPPER_UCOSLAM_WRAPPER_H_

#include <memory>
#include <opencv4/opencv2/opencv.hpp>

#include <ucoslam/ucoslamtypes.h>
#include <ucoslam/imageparams.h>

namespace ucoslam {

class UcoSlam;

class Map;

class UcoSLAMWrapper
{
private:

  UcoSlam* mUcoSLAM;

  std::shared_ptr<Map> mMap;

public:

  UcoSLAMWrapper();

  ~UcoSLAMWrapper();

  void clearMap();

  void setParams(const ucoslam::Params& params);

  cv::Mat process(cv::Mat image, const ucoslam::ImageParams& imageParams, uint frameIdx);
};

} // namespace ucoslam

#endif // _UCOSLAM_WRAPPER_UCOSLAM_WRAPPER_H_

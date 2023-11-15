
#include "ucoslam_wrapper/ucoslam_wrapper.h"

#include <memory>
#include <ucoslam/ucoslam.h>

namespace ucoslam {

UcoSLAMWrapper::UcoSLAMWrapper() :
mMap(std::make_shared<ucoslam::Map>()),
mUcoSLAM(new ucoslam::UcoSlam())
{}

UcoSLAMWrapper::~UcoSLAMWrapper()
{
  delete mUcoSLAM;
}

void UcoSLAMWrapper::clearMap()
{
  mMap->clear();
}

void UcoSLAMWrapper::setParams(const ucoslam::Params& params)
{
  mUcoSLAM->setParams(mMap, params);
}

cv::Mat UcoSLAMWrapper::process(cv::Mat image, const ucoslam::ImageParams& imageParams, uint frameIdx)
{
  return mUcoSLAM->process(image, imageParams, frameIdx);
}

} // namespace ucoslam
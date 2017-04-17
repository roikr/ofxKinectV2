//
//  ofRGBPacketProcessor.cpp
//
//  Created by Theodore Watson on 6/23/14.
//
//

#include "ofRGBPacketProcessor.h"

namespace libfreenect2
{

ofRGBPacketProcessor::ofRGBPacketProcessor(){
    newFrame();
}

ofRGBPacketProcessor::~ofRGBPacketProcessor(){

}

void ofRGBPacketProcessor::newFrame(){
    frame = new Frame(1920, 1080, 4);
}

void ofRGBPacketProcessor::process(const libfreenect2::RgbPacket &packet){
    ofBuffer tmp;
    tmp.set( ( char * )packet.jpeg_buffer, (unsigned int)packet.jpeg_buffer_length);
    
    if( ofLoadImage(pix, tmp) ){
        pix.setImageType(OF_IMAGE_COLOR_ALPHA);
        memcpy(frame->data, pix.getPixels(), pix.size());
        
    
      if(listener_->onNewFrame(Frame::Color, frame)){
        newFrame();
      }
    }

}

};

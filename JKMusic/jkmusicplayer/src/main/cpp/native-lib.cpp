#include <jni.h>
#include <string>
#include <android/log.h>
extern "C" {
#include <libavutil/avutil.h>
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
}

#define LOGD(format, ...)  __android_log_print(ANDROID_LOG_INFO,  "native-lib", format, ##__VA_ARGS__)

extern "C"
JNIEXPORT void JNICALL
Java_com_smallest_funny_jkmusicplayer_Demo_testMusicPlayer(JNIEnv *env, jobject instance) {
    av_register_all();
    AVCodec *c_temp = av_codec_next(NULL);
    while(c_temp != NULL){
        switch(c_temp->type){
            case AVMEDIA_TYPE_VIDEO:
                LOGD("[Video],[%10s]\n",c_temp->name);
                break;
            case AVMEDIA_TYPE_AUDIO:
                LOGD("[Audio],[%10s]\n",c_temp->name);
                break;
            default:
                LOGD("[Other],[%10s]\n",c_temp->name);
                break;
        }
        c_temp=c_temp->next;
    }
}

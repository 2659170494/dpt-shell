//
// Created by luoyesiqiu
//

#ifndef DPT_DPT_H
#define DPT_DPT_H
#include <jni.h>
#include <string>
#include <inttypes.h>
#include <map>
#include <unordered_map>
#include <vector>
#include <dlfcn.h>
#include <unistd.h>
#include <pthread.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include "dex/CodeItem.h"
#include "common/dpt_log.h"
#include "dpt_hook.h"
#include "dex/MultiDexCode.h"
#include "dpt_jni.h"
#include "dpt_util.h"
#include "reflect/dalvik_system_BaseDexClassLoader.h"
#include "reflect/dalvik_system_DexPathList.h"
#include "reflect/java_util_ArrayList.h"
#include "reflect/java_io_File.h"
#include "reflect/android_app_Application.h"
#include "reflect/android_app_LoadedApk.h"


void callRealApplicationOnCreate(JNIEnv *env, jclass, jstring realApplicationClassName);

void callRealApplicationAttach(JNIEnv *env, jclass, jobject context,
                                         jstring realApplicationClassName);

INIT_ARRAY_SECTION void init_dpt();
void init_app(JNIEnv* env,jclass __unused,jobject context);
void readCodeItem(uint8_t *data,size_t data_len);
jstring readAppComponentFactory(JNIEnv *env,jclass __unused);
jstring readApplicationName(JNIEnv *env, jclass __unused);
jobjectArray makePathElements(JNIEnv* env);
void mergeDexElements(JNIEnv* env,jclass __unused,jobject targetClassLoader);
void removeDexElements(JNIEnv* env,jclass __unused,jobject classLoader,jstring elementName);
void replaceApplication(JNIEnv *env, jclass __unused, jstring originApplication);
void replaceApplicationOnActivityThread(JNIEnv *env,jclass __unused, jobject realApplication);
void replaceApplicationOnLoadedApk(JNIEnv *env, jclass __unused, jobject realApplication);
std::unordered_map<int,std::unordered_map<int,dpt::data::CodeItem*>*> dexMap;

#endif //DPT_DPT_H

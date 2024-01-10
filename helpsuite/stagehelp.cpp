#include "stagehelp.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
HelpStage::HelpStage() { _stage = StageManager::GetInstance(__FILE__); _stage->_help(); }

/*!
 * @brief   Default Deconstructor
*/
HelpStage::~HelpStage() { }

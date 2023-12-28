/*!
 * @class   HelpStage stagehelp.h stagehelp.cpp
 * @brief   Help details about the StageManager itself. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
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
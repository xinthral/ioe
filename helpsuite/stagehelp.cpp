/*!
 * @class   HelpStage stagehelp.h stagehelp.cpp
 * @brief   Help details about the StageManager itself. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
#include "stagehelp.h"

/*!
 * @brief   Default Constructor
*/
HelpStage::HelpStage() { _stage = StageManager::GetInstance(__FILE__); _stage->_help(); }

/*!
 * @brief   Default Deconstructor
*/
HelpStage::~HelpStage() { }
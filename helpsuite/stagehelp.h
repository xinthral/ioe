#ifndef HELPSTAGE_H
#define HELPSTAGE_H

#include "basehelp.h"

/*!
 * @class   HelpStage stagehelp.h stagehelp.cpp
 * @brief   Help details about the StageManager itself. 
 * @details Includes features like how it works, hints 
 *          working with the engine and more.
*/
class HelpStage : public BaseHelp {
protected:
private:
  StageManager* _stage;   //!< Placeholder StageManager Object

public:
  /*!
   * @brief   Default Constructor
  */
  HelpStage();

  /*!
   * @brief   Default Deconstructor
  */
  ~HelpStage();
};

#endif // HELPSTAGE_H //

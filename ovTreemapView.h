/*========================================================================
  OpenView -- http://openview.kitware.com

  Copyright 2012 Kitware, Inc.

  Licensed under the BSD license. See LICENSE file for details.
 ========================================================================*/
#ifndef ovTreemapView_h
#define ovTreemapView_h

#include "ovView.h"
#include "vtkNew.h"
#include "vtkSmartPointer.h"
#include "vtkTooltipItem.h"

class ovTreemapItem;
class vtkContextView;
class vtkTable;

class ovTreemapView : public ovView
{
  Q_OBJECT
public:
  ovTreemapView(QObject *parent);
  ~ovTreemapView();

  virtual bool acceptsType(const QString &type);
  virtual void setData(vtkDataObject *data, vtkContextView *view);
  virtual QString name();

  virtual QStringList attributes();
  virtual QStringList attributeOptions(QString attribute);
  virtual void setAttribute(QString attribute, QString value);
  virtual QString getAttribute(QString attribute);

protected:
  void generateTreemap();

  QString m_group;
  QString m_color;
  QString m_size;
  QString m_strategy;
  QString m_hover;
  vtkNew<ovTreemapItem> m_item;
  vtkSmartPointer<vtkTable> m_table;
};

#endif

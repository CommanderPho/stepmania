/* EditMenu - UI on Edit Menu screen.  Create Steps, delete Steps, or launch Steps in editor. */

#ifndef EDIT_MENU_H
#define EDIT_MENU_H

#include "ActorFrame.h"
#include "FadingBanner.h"
#include "TextBanner.h"
#include "GameConstantsAndTypes.h"
#include "DifficultyMeter.h"
#include "RandomSample.h"
#include "EnumHelper.h"


enum EditMenuRow 
{ 
	ROW_GROUP, 
	ROW_SONG, 
	ROW_STEPS_TYPE, 
	ROW_STEPS,
	ROW_SOURCE_STEPS_TYPE, 
	ROW_SOURCE_STEPS, 
	ROW_ACTION, 
	NUM_EDIT_MENU_ROWS 
};
#define FOREACH_EditMenuRow( emr ) FOREACH_ENUM( EditMenuRow, NUM_EDIT_MENU_ROWS, emr )
const CString& RadarCategoryToString( RadarCategory cat );
const CString& RadarCategoryToThemedString( RadarCategory cat );


class EditMenu: public ActorFrame 
{
public:
	EditMenu();
	~EditMenu();
	virtual void DrawPrimitives();

	bool CanGoUp();
	bool CanGoDown();
	bool CanGoLeft();
	bool CanGoRight();

	void Up();
	void Down();
	void Left();
	void Right();

	void RefreshAll();

	CString			GetSelectedGroup() const			{ ASSERT(m_iSelection[ROW_GROUP]			< (int)m_sGroups.size());		return m_sGroups[m_iSelection[ROW_GROUP]]; }
	Song*			GetSelectedSong() const				{ ASSERT(m_iSelection[ROW_SONG]				< (int)m_pSongs.size());		return m_pSongs[m_iSelection[ROW_SONG]]; }
	StepsType		GetSelectedStepsType() const		{ ASSERT(m_iSelection[ROW_STEPS_TYPE]		< (int)m_StepsTypes.size());	return m_StepsTypes[m_iSelection[ROW_STEPS_TYPE]]; }
	Steps*			GetSelectedSteps() const			{ ASSERT(m_iSelection[ROW_STEPS]			< (int)m_vpSteps.size());		return m_vpSteps[m_iSelection[ROW_STEPS]]; }
	StepsType		GetSelectedSourceStepsType() const	{ ASSERT(m_iSelection[ROW_SOURCE_STEPS_TYPE]< (int)m_StepsTypes.size());	return m_StepsTypes[m_iSelection[ROW_SOURCE_STEPS_TYPE]]; }
	Steps*			GetSelectedSourceSteps() const		{ ASSERT(m_iSelection[ROW_SOURCE_STEPS]		< (int)m_vpSourceSteps.size());	return m_vpSourceSteps[m_iSelection[ROW_SOURCE_STEPS]]; }
	EditMenuAction	GetSelectedAction() const			{ ASSERT(m_iSelection[ROW_ACTION]			< (int)m_Actions.size());		return m_Actions[m_iSelection[ROW_ACTION]]; }

	Difficulty	GetSelectedDifficulty();
	Difficulty	GetSelectedSourceDifficulty();

private:
	Sprite	m_sprArrows[2];

	EditMenuRow m_SelectedRow;
	int			m_iSelection[NUM_EDIT_MENU_ROWS];
	BitmapText	m_textLabel[NUM_EDIT_MENU_ROWS];
	BitmapText	m_textValue[NUM_EDIT_MENU_ROWS];

	FadingBanner	m_GroupBanner;
	FadingBanner	m_SongBanner;
	TextBanner		m_SongTextBanner;
	DifficultyMeter	m_Meter;
	DifficultyMeter	m_SourceMeter;


	vector<Difficulty>			m_vDifficulties;
	vector<Difficulty>			m_vSourceDifficulties;

	CStringArray				m_sGroups;
	vector<Song*>				m_pSongs;
	vector<StepsType>			m_StepsTypes;
	vector<Steps*>				m_vpSteps;
	vector<Steps*>				m_vpSourceSteps;
	vector<EditMenuAction>		m_Actions;

	void OnRowValueChanged( EditMenuRow row );
	void ChangeToRow( EditMenuRow newRow );

	RandomSample	m_soundChangeRow;
	RandomSample	m_soundChangeValue;
};

#endif

/*
 * (c) 2001-2004 Chris Danford
 * All rights reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, and/or sell copies of the Software, and to permit persons to
 * whom the Software is furnished to do so, provided that the above
 * copyright notice(s) and this permission notice appear in all copies of
 * the Software and that both the above copyright notice(s) and this
 * permission notice appear in supporting documentation.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF
 * THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS
 * INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

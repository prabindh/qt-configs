/******************************************************************************
 * Name         : ews.h
 *
 * Copyright    : 2008, 2009 by Imagination Technologies Limited.
 *              : All rights reserved. No part of this software, either
 *              : material or conceptual may be copied or distributed,
 *              : transmitted, transcribed, stored in a retrieval system or
 *              : translated into any human or computer language in any form
 *              : by any means, electronic, mechanical, manual or otherwise,
 *              : or disclosed to third parties without the express written
 *              : permission of Imagination Technologies Limited, Home Park
 *              : Estate, Kings Langley, Hertfordshire, WD4 8LZ, U.K.
 *
 * Platform     : ANSI
 *
 *****************************************************************************/

/* EWSlib library header file */

#if !defined(EWS_H)
#define EWS_H

#include "ews_types.h"

#ifdef __cplusplus
extern "C" {
#endif

EWS_DISPLAY EWSOpenDisplay(int iDisplay, int iClientFlags);
EWS_BOOL EWSValidDisplay(EWS_DISPLAY sDisplay);

EWS_WINDOW EWSCreateWindow(EWS_DISPLAY sDisplay,  EWS_COORD sPosition,
						   EWS_SIZE sSize, EWS_PIXELFORMAT ePixelFormat,
						   EWS_ROTATION eRotation);

EWS_PIXMAP EWSCreatePixmap(EWS_DISPLAY sDisplay, EWS_SIZE sSize, EWS_PIXELFORMAT ePixelFormat);

void EWSNoOp(void);
EWS_ATOM EWSInternAtom(const char *pszName);

EWS_BOOL EWSSetProperty(EWS_WINDOW sWindow, EWS_ATOM sName, unsigned long uiLength,
						const void *pvData);
EWS_BOOL EWSSetRestrictedProperty(EWS_WINDOW sWindow, EWS_ATOM sName,
								  unsigned long uiLength, const void *pvData);
EWS_BOOL EWSSetPropertyEx(EWS_WINDOW sWindow, int uiNamespace,
						  EWS_ATOM sName, unsigned long uiLength,
						  const void *pvData);

EWS_BOOL EWSGetProperty(EWS_WINDOW sWindow, EWS_ATOM sName,
						unsigned long *puiLengthReturn, void **ppvDataReturn);
EWS_BOOL EWSGetRestrictedProperty(EWS_WINDOW sWindow, EWS_ATOM sName,
								  unsigned long *puiLengthReturn,
								  void **ppvDataReturn);
EWS_BOOL EWSGetPropertyEx(EWS_WINDOW sWindow, int uiNamespace,
						  EWS_ATOM sName, unsigned long *puiLengthReturn,
						  void **ppvDataReturn);

EWS_BOOL EWSWriteProperty(EWS_WINDOW sWindow, EWS_ATOM sName, int uiWriteFlags,
						  unsigned long uiPosition, unsigned int uiLength,
						  const void *pvData);
EWS_BOOL EWSWriteRestrictedProperty(EWS_WINDOW sWindow, EWS_ATOM sName,
									int uiWriteFlags, unsigned long uiPosition,
									unsigned int uiLength, const void *pvData);
EWS_BOOL EWSWritePropertyEx(EWS_WINDOW sWindow, int uiNamespace,
							EWS_ATOM sName, int uiWriteFlags,
							unsigned long uiPosition,
							unsigned int uiLength, const void *pvData);

EWS_BOOL EWSPropertyLength(EWS_WINDOW sWindow, EWS_ATOM sName,
						   unsigned long *puiLengthReturn);
EWS_BOOL EWSRestrictedPropertyLength(EWS_WINDOW sWindow, EWS_ATOM sName,
									 unsigned long *puiLengthReturn);
EWS_BOOL EWSPropertyLengthEx(EWS_WINDOW sWindow, int uiNamespace,
							 EWS_ATOM sName, unsigned long *puiLengthReturn);

void EWSDestroyWindow(EWS_WINDOW sWindow);
void EWSDestroyPixmap(EWS_PIXMAP sPixmap);
void EWSCloseDisplay(EWS_DISPLAY sDisplay);

/* Presentation */
EWS_BOOL EWSGetSurfaceInfo(EWS_WINDOW sWindow,
						   EWS_SURFACE_INFO *psSurfaceInfoReturn);
void EWSBlitWindow(EWS_WINDOW sWindow);

/* Events */
void EWSNextEvent(EWS_EVENT *psEventReturn);
EWS_BOOL EWSNextEventIfAvailable(EWS_EVENT *psEventReturn);
EWS_BOOL EWSNextQueuedEvent(EWS_EVENT *psEventReturn);
void EWSPeekEvent(EWS_EVENT *psEventReturn);
EWS_BOOL EWSPeekEventIfAvailable(EWS_EVENT *psEventReturn);
unsigned long EWSEventsQueued(void);
void EWSClearEventQueue(void);
void EWSRegisterEventHandler(EWS_EVENT_HANDLER pfnNewEventHandler);
EWS_BOOL EWSUnregisterEventHandler(EWS_EVENT_HANDLER pfnNewEventHandler);

/* WM functions */
void EWSListWindows(EWS_DISPLAY sDisplay, EWS_CLIENT sOwner,
					unsigned int *puiNumWindowsReturn,
					EWS_WINDOW **ppsWindowsReturn);
void EWSListProperties(EWS_WINDOW sWindow,
					   unsigned int *puiNumPropertiesReturn,
					   EWS_ATOM **ppsAtomsReturn);
void EWSListRestrictedProperties(EWS_WINDOW sWindow,
								 unsigned int *puiNumPropertiesReturn,
								 EWS_ATOM **ppsAtomsReturn);
void EWSListPropertiesEx(EWS_WINDOW sWindow, int uiNamespace,
						 unsigned int *puiNumPropertiesReturn,
						 EWS_ATOM **ppsAtomsReturn);
EWS_BOOL EWSAtomName(EWS_ATOM sAtom, char **ppszNameReturn);

/* Functions for converting between property data and EWS types */
void EWSPackCoord(EWS_COORD sCoord, void *pvDest);
EWS_COORD EWSUnpackCoord(const void *pvData);
void EWSPackSize(EWS_SIZE sSize, void *pvDest);
EWS_SIZE EWSUnpackSize(const void *pvData);
void EWSPackZOrder(EWS_ZORDER uiZOrder, void *pvDest);
EWS_ZORDER EWSUnpackZOrder(const void *pvData);
void EWSPackPixelFormat(EWS_PIXELFORMAT ePixelFormat, void *pvDest);
EWS_PIXELFORMAT EWSUnpackPixelFormat(const void *pvData);
void EWSPackRotation(EWS_ROTATION eRotation, void *pvDest);
EWS_ROTATION EWSUnpackRotation(const void *pvData);

/* Error handling */
void EWSDefaultErrorHandler(int iError);
void EWSSetErrorHandler(EWS_ERROR_HANDLER pfnNewErrorHandler);
EWS_BOOL EWSServerRunning(void);

/* Framerate counter */
void EWSFrameComplete(EWS_WINDOW sWindow);

/* Functions to lock buffers for software rendering */
EWS_BOOL EWSLockBuffer(EWS_WINDOW sWindow, int *piBufferIndexReturn);
void EWSUnlockBuffer(EWS_WINDOW sWindow, int iBufferIndex);

#ifdef __cplusplus
}
#endif

#endif /* EWS_H */

/******************************************************************************
   End of file (ews.h)
 ******************************************************************************/
